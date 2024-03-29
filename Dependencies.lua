
-- PEngine Dependencies

VULKAN_SDK = os.getenv("VULKAN_SDK")

IncludeDir = {}
IncludeDir["stb_image"] = "%{wks.location}/PEngine/vendor/stb_image"
IncludeDir["yaml_cpp"] = "%{wks.location}/PEngine/vendor/yaml-cpp/include"
IncludeDir["GLFW"] = "%{wks.location}/PEngine/vendor/GLFW/include"
IncludeDir["Glad"] = "%{wks.location}/PEngine/vendor/Glad/include"
IncludeDir["ImGui"] = "%{wks.location}/PEngine/vendor/ImGui"
IncludeDir["ImGuizmo"] = "%{wks.location}/PEngine/vendor/ImGuizmo"
IncludeDir["glm"] = "%{wks.location}/PEngine/vendor/glm"
IncludeDir["entt"] = "%{wks.location}/PEngine/vendor/entt/include"
IncludeDir["shaderc"] = "%{wks.location}/PEngine/vendor/shaderc/include"
IncludeDir["SPIRV_Cross"] = "%{wks.location}/PEngine/vendor/SPIRV-Cross"
IncludeDir["VulkanSDK"] = "%{VULKAN_SDK}/Include"

LibraryDir = {}

LibraryDir["VulkanSDK"] = "%{VULKAN_SDK}/Lib"
LibraryDir["VulkanSDK_Debug"] = "%{wks.location}/PEngine/vendor/VulkanSDK/Lib"
LibraryDir["VulkanSDK_DebugDLL"] = "%{wks.location}/PEngine/vendor/VulkanSDK/Bin"

Library = {}
Library["Vulkan"] = "%{LibraryDir.VulkanSDK}/vulkan-1.lib"
Library["VulkanUtils"] = "%{LibraryDir.VulkanSDK}/VkLayer_utils.lib"

Library["ShaderC_Debug"] = "%{LibraryDir.VulkanSDK_Debug}/shaderc_sharedd.lib"
Library["SPIRV_Cross_Debug"] = "%{LibraryDir.VulkanSDK_Debug}/spirv-cross-cored.lib"
Library["SPIRV_Cross_GLSL_Debug"] = "%{LibraryDir.VulkanSDK_Debug}/spirv-cross-glsld.lib"
Library["SPIRV_Tools_Debug"] = "%{LibraryDir.VulkanSDK_Debug}/SPIRV-Toolsd.lib"

Library["ShaderC_Release"] = "%{LibraryDir.VulkanSDK}/shaderc_shared.lib"
Library["SPIRV_Cross_Release"] = "%{LibraryDir.VulkanSDK}/spirv-cross-core.lib"
Library["SPIRV_Cross_GLSL_Release"] = "%{LibraryDir.VulkanSDK}/spirv-cross-glsl.lib"