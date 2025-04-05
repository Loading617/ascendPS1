#include <elements.hpp>
#include "renderer/vulkan_renderer.hpp"

using namespace cycfi::elements;

int main(int argc, char* argv[]) {
    app _app(argc, argv, "ascendPS1");
    window _win(_app.name(), {1280, 720});
    view _view(_win);

    VulkanRenderer renderer;
    renderer.init(_win.native_handle());
    renderer.createGraphicsPipeline();

    _view.content(
        margin({20, 20, 20, 20}, label("ascendPS1"))
    );

    return _app.run();
}
