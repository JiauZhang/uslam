# ifndef __DESCRIPTOR_FACTORY__H__
# define __DESCRIPTOR_FACTORY__H__

#include <map>
#include <string>
#include <vector>

#include "descriptor.hpp"

namespace uslam {

class DescriptorRegistry {
 public:
  typedef shared_ptr<Descriptor> (*Creator)(const DescriptorParameter&);
  typedef std::map<string, Creator> CreatorRegistry;

  static CreatorRegistry& Registry() {
    static CreatorRegistry* g_registry_ = new CreatorRegistry();
    return *g_registry_;
  }

  // Adds a creator.
  static void AddCreator(const string& type, Creator creator) {
    CreatorRegistry& registry = Registry();
    if (registry.count(type) != 0) {
        std::cout << "Descriptor type " << type << " already registered.";
    } else {
		registry[type] = creator;
	}
  }

  // Get a descriptor using a DescriptorParameter.
  static shared_ptr<Descriptor> CreateDescriptor(const DescriptorParameter& param) {
    const string& type = param.type;
    CreatorRegistry& registry = Registry();
    if (registry.count(type) != 1) {
		std::cout << "Unknown Descriptor type: " << type
				  << " (known types: " << DescriptorTypeListString() << ")";
		return NULL;
	} else {
		return registry[type](param);
	}
  }

  static vector<string> DescriptorTypeList() {
    CreatorRegistry& registry = Registry();
    vector<string> descriptor_types;
    for (typename CreatorRegistry::iterator iter = registry.begin();
         iter != registry.end(); ++iter) {
      descriptor_types.push_back(iter->first);
    }
    return descriptor_types;
  }

 private:
  // Descriptor registry should never be instantiated - everything is done with its
  // static variables.
  DescriptorRegistry() {}

  static string DescriptorTypeListString() {
    vector<string> descriptor_types = DescriptorTypeList();
    string descriptor_types_str;
    for (vector<string>::iterator iter = descriptor_types.begin();
         iter != descriptor_types.end(); ++iter) {
      if (iter != descriptor_types.begin()) {
        descriptor_types_str += ", ";
      }
      descriptor_types_str += *iter;
    }
    return descriptor_types_str;
  }
};


class DescriptorRegisterer {
 public:
  DescriptorRegisterer(const string& type,
                  shared_ptr<Descriptor> (*creator)(const DescriptorParameter&)) {
    DescriptorRegistry::AddCreator(type, creator);
  }
};


#define REGISTER_DESCRIPTOR_CREATOR(type, creator)                                  \
  static DescriptorRegisterer g_creator_##type(#type, creator)

#define REGISTER_DESCRIPTOR_CLASS(type)                                             \
  shared_ptr<Descriptor> Creator_##type##Descriptor(const DescriptorParameter& param) \
  {                                                                            \
    return shared_ptr<Descriptor>(new type##Descriptor(param));           \
  }                                                                            \
  REGISTER_DESCRIPTOR_CREATOR(type, Creator_##type##Descriptor)

	
} // namespace uslam

# endif