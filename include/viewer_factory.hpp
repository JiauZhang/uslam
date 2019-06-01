#ifndef __VIEWER_FACTORY__H__
#define __VIEWER_FACTORY__H__

#include "viewer.hpp"
#include "common.hpp"
#include "parameters.hpp"

namespace uslam {

class ViewerParameter;
class Viewer;

class ViewerRegistry {
 public:
  typedef std::shared_ptr<Viewer> (*Creator)(const ViewerParameter&);
  typedef map<std::string, Creator> CreatorRegistry;

  static CreatorRegistry& Registry();

  // Adds a creator.
  static void AddCreator(const std::string& type, Creator creator);

  // Get a viewer using a ViewerParameter.
  static std::shared_ptr<Viewer> CreateViewer(const ViewerParameter& param);

  static std::vector<std::string> ViewerTypeList();

 private:
  // Viewer registry should never be instantiated - everything is done with its
  // static variables.
  ViewerRegistry() {}

  static std::string ViewerTypeListString();
}; // ViewerRegistry

class ViewerRegisterer {
 public:
  ViewerRegisterer(const std::string& type, \
					 std::shared_ptr<Viewer> (*creator)(const ViewerParameter&)) {
    ViewerRegistry::AddCreator(type, creator);
  }
};


#define REGISTER_VIEWER_CREATOR(type, creator)                               \
  static ViewerRegisterer g_creator_##type(#type, creator);

#define REGISTER_VIEWER_CLASS(type)                                          \
  std::shared_ptr<Viewer> Creator_##type##Viewer(const ViewerParameter& param) 	 \
  {                                                                          \
    return std::shared_ptr<Viewer>(new type##Viewer(param));           			 \
  }                                                                          \
  REGISTER_VIEWER_CREATOR(type, Creator_##type##Viewer)
	
} // namespace uslam

# endif