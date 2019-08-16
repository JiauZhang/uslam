# ifndef __MATCHER_FACTORY__H__
# define __MATCHER_FACTORY__H__

#include <map>
#include <string>
#include <vector>

#include "matcher.hpp"

namespace uslam {

class MatcherRegistry {
 public:
  typedef shared_ptr<Matcher> (*Creator)(const MatcherParameter&);
  typedef std::map<string, Creator> CreatorRegistry;

  static CreatorRegistry& Registry() {
    static CreatorRegistry* g_registry_ = new CreatorRegistry();
    return *g_registry_;
  }

  // Adds a creator.
  static void AddCreator(const string& type, Creator creator) {
    CreatorRegistry& registry = Registry();
    if (registry.count(type) != 0) {
        std::cout << "Matcher type " << type << " already registered.";
    } else {
		registry[type] = creator;
	}
  }

  // Get a matcher using a MatcherParameter.
  static shared_ptr<Matcher> CreateMatcher(const MatcherParameter& param) {
    const string& type = param.type;
    CreatorRegistry& registry = Registry();
    if (registry.count(type) != 1) {
		std::cout << "Unknown Matcher type: " << type
				  << " (known types: " << MatcherTypeListString() << ")";
		return NULL;
	} else {
		return registry[type](param);
	}
  }

  static vector<string> MatcherTypeList() {
    CreatorRegistry& registry = Registry();
    vector<string> matcher_types;
    for (typename CreatorRegistry::iterator iter = registry.begin();
         iter != registry.end(); ++iter) {
      matcher_types.push_back(iter->first);
    }
    return matcher_types;
  }

 private:
  // Matcher registry should never be instantiated - everything is done with its
  // static variables.
  MatcherRegistry() {}

  static string MatcherTypeListString() {
    vector<string> matcher_types = MatcherTypeList();
    string matcher_types_str;
    for (vector<string>::iterator iter = matcher_types.begin();
         iter != matcher_types.end(); ++iter) {
      if (iter != matcher_types.begin()) {
        matcher_types_str += ", ";
      }
      matcher_types_str += *iter;
    }
    return matcher_types_str;
  }
};

class MatcherRegisterer {
 public:
  MatcherRegisterer(const string& type,
                  shared_ptr<Matcher> (*creator)(const MatcherParameter&)) {
    MatcherRegistry::AddCreator(type, creator);
  }
};


#define REGISTER_MATCHER_CREATOR(type, creator)                                  \
  static MatcherRegisterer g_creator_##type(#type, creator)

#define REGISTER_MATCHER_CLASS(type)                                             \
  shared_ptr<Matcher> Creator_##type##Matcher(const MatcherParameter& param) \
  {                                                                            \
    return shared_ptr<Matcher>(new type##Matcher(param));           \
  }                                                                            \
  REGISTER_MATCHER_CREATOR(type, Creator_##type##Matcher)

	
} // namespace uslam

# endif