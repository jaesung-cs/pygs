#ifndef PYGS_ENGINE_VULKAN_GRAPHICS_PIPELINE_H
#define PYGS_ENGINE_VULKAN_GRAPHICS_PIPELINE_H

#include <memory>
#include <string>

#include <vulkan/vulkan.h>

#include "context.h"
#include "pipeline_layout.h"

namespace pygs {
namespace vk {

struct GraphicsPipelineCreateInfo {
  PipelineLayout layout;
  std::string vertex_shader;
  std::string fragment_shader;
  VkPrimitiveTopology topology = VK_PRIMITIVE_TOPOLOGY_POINT_LIST;
  std::vector<VkVertexInputBindingDescription> input_bindings;
  std::vector<VkVertexInputAttributeDescription> input_attributes;
  bool depth_test = false;
  bool depth_write = false;
};

class GraphicsPipeline {
 public:
  GraphicsPipeline();

  GraphicsPipeline(Context context,
                   const GraphicsPipelineCreateInfo& create_info);

  ~GraphicsPipeline();

  operator VkPipeline() const;

 private:
  class Impl;
  std::shared_ptr<Impl> impl_;
};

}  // namespace vk
}  // namespace pygs

#endif  // PYGS_ENGINE_VULKAN_GRAPHICS_PIPELINE_H
