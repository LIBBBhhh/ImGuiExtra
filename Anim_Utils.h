// File: Anim_Utils.h
// Created on: Thu Oct  5 23:09:57 +04 2023
// User: root

#include <imgui_internal.h>

#include <imgui.h>

#ifndef ANIM_UTILS_H
#define ANIM_UTILS_H

float deltaTime = 0.0f;
float lastFrameTime = 0.0f;

bool animatedCheckboxVisible = true;
bool checkboxValue = false;


namespace AnimUtil {
void DrawText2(float fontSize, ImVec2 position, ImVec4 color, const char *text, bool center = true) {
        auto background = ImGui::GetBackgroundDrawList();
        if(background) {
            if (center) {
                ImVec2 textSize = ImGui::CalcTextSize(text);
                ImVec2 centeredPosition = ImVec2(position.x - (textSize.x * 0.5f), position.y - (textSize.y * 0.5f));
                background->AddText(NULL, fontSize, centeredPosition, ImColor(color.x, color.y, color.z, color.w), text);
            } else {
                background->AddText(NULL, fontSize, position, ImColor(color.x, color.y, color.z, color.w), text);
            }
        }
    }

void UpdateDeltaTime() {
    float currentFrameTime = ImGui::GetTime();
    deltaTime = currentFrameTime - lastFrameTime;
    lastFrameTime = currentFrameTime;
}

float GetDeltaTime() {
    static auto lastTime = std::chrono::high_resolution_clock::now();
    auto currentTime = std::chrono::high_resolution_clock::now();
    auto deltaTime = std::chrono::duration<float>(currentTime - lastTime).count();
    lastTime = currentTime;
    return deltaTime;
}



float Lerp(float a, float b, float t) {
    return a + t * (b - a);
}


}

// Comment if you working Android studio 
#endif ANIM_UTILS_H
