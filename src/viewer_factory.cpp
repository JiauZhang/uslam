#include "viewer_factory.hpp"
#include "common.hpp"
#include "parameters.hpp"

namespace uslam {
	
ViewerRegistry::CreatorRegistry& ViewerRegistry::Registry() {
    static ViewerRegistry::CreatorRegistry* g_registry_ = new ViewerRegistry::CreatorRegistry();
    return *g_registry_;
}

void ViewerRegistry::AddCreator(const std::string& type, Creator creator) {
    ViewerRegistry::CreatorRegistry& registry = Registry();
    if (registry.count(type) != 0) {
        std::cout << "Viewer type " << type << " already registered.";
	} else {
		registry[type] = creator;
	}
}

std::shared_ptr<Viewer> ViewerRegistry::CreateViewer(const ViewerParameter& param) {
    const std::string &type = param.type;
    CreatorRegistry& registry = Registry();
    if (registry.count(type) != 1) {
		std::cout << "Unknown Viewer type: " << type \
				  << " (known types: " << ViewerTypeListString() << ")\n";
		return NULL;
	} else {
		return registry[type](param);
	}
}

std::vector<std::string> ViewerRegistry::ViewerTypeList() {
    CreatorRegistry& registry = Registry();
    std::vector<std::string> viewer_types;
    for (typename CreatorRegistry::iterator iter = registry.begin();
         iter != registry.end(); ++iter) {
      viewer_types.push_back(iter->first);
    }
    return viewer_types;
}

std::string ViewerRegistry::ViewerTypeListString() {
    std::vector<std::string> viewer_types = ViewerTypeList();
    std::string viewer_types_str;
    for (std::vector<std::string>::iterator iter = viewer_types.begin();
         iter != viewer_types.end(); ++iter) {
      if (iter != viewer_types.begin()) {
        viewer_types_str += ", ";
      }
      viewer_types_str += *iter;
    }
    return viewer_types_str;
}
	
} // namespace uslam