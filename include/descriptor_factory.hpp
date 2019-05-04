# ifndef __MATCHER_FACTORY__H__
# define __MATCHER_FACTORY__H__

#include <map>
#include <string>
#include <vector>

#include "descriptor.hpp"

namespace uslam {

template <typename Dtype>
class Descriptor;

template <typename Dtype>
class DescriptorRegistry {
 public:
  typedef shared_ptr<Descriptor<Dtype> > (*Creator)(const DescriptorParameter&);
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
  static shared_ptr<Descriptor<Dtype> > CreateDescriptor(const DescriptorParameter& param) {
    const string& type = param.type();
    CreatorRegistry& registry = Registry();
    if (registry.count(type) != 1) {
		std::cout << "Unknown Descriptor type: " << type
				  << " (known types: " << DescriptorTypeListString() << ")";
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


template <typename Dtype>
class DescriptorRegisterer {
 public:
  DescriptorRegisterer(const string& type,
                  shared_ptr<Descriptor<Dtype> > (*creator)(const DescriptorParameter&)) {
    DescriptorRegistry<Dtype>::AddCreator(type, creator);
  }
};


#define REGISTER_MATCHER_CREATOR(type, creator)                                  \
  static DescriptorRegisterer<float> g_creator_f_##type(#type, creator<float>);     \
  static DescriptorRegisterer<double> g_creator_d_##type(#type, creator<double>)    \

#define REGISTER_MATCHER_CLASS(type)                                             \
  template <typename Dtype>                                                    \
  shared_ptr<Descriptor<Dtype> > Creator_##type##Descriptor(const DescriptorParameter& param) \
  {                                                                            \
    return shared_ptr<Descriptor<Dtype> >(new type##Descriptor<Dtype>(param));           \
  }                                                                            \
REGISTER_MATCHER_CREATOR(type, Creator_##type##Descriptor)

	
} // namespace uslam

# endif