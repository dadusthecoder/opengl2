#include "Renderer/renderer.h"

inline void RenderGizmoTest(const glm::mat4& viewMatrix, const glm::mat4& projectionMatrix)
{
    
   
    static glm::mat4 testModelMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));
    static ImGuizmo::OPERATION currentOp = ImGuizmo::TRANSLATE;

    ImGuizmo::SetOrthographic(false);
    ImGuizmo::SetDrawlist();

    ImGuiIO& io = ImGui::GetIO();
    ImGuizmo::SetRect(0, 0, io.DisplaySize.x, io.DisplaySize.y);  // Make sure origin is 0,0

    ImGui::Begin("Gizmo Test");

    if (ImGui::RadioButton("Translate", currentOp == ImGuizmo::TRANSLATE)) currentOp = ImGuizmo::TRANSLATE;
    ImGui::SameLine();
    if (ImGui::RadioButton("Rotate", currentOp == ImGuizmo::ROTATE)) currentOp = ImGuizmo::ROTATE;
    ImGui::SameLine();
    if (ImGui::RadioButton("Scale", currentOp == ImGuizmo::SCALE)) currentOp = ImGuizmo::SCALE;

    ImGuizmo::Manipulate(glm::value_ptr(viewMatrix), glm::value_ptr(projectionMatrix),
        currentOp, ImGuizmo::WORLD,
        glm::value_ptr(testModelMatrix));

    if (ImGuizmo::IsUsing())
    {
        glm::vec3 skew;
        glm::vec4 perspective;
        glm::quat rotation;
        glm::vec3 scale;
        glm::vec3 position;

        glm::decompose(testModelMatrix, scale, rotation, position, skew, perspective);
        glm::vec3 euler = glm::degrees(glm::eulerAngles(rotation));
        ImGui::Text("Position: %.2f, %.2f, %.2f", position.x, position.y, position.z);
        ImGui::Text("Rotation: %.2f, %.2f, %.2f", euler.x, euler.y, euler.z);
    }
    ImGui::End();
    

}
