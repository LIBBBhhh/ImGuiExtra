// ImGuiExtra Version 1.54 Get Started

// Documentation:

/**
 * @file ImGuiExtra.cpp
 *
 * @brief ImGuiExtra - Custom ImGui Widgets and Utilities.
 *
 * ImGuiExtra is a set of custom ImGui widgets and utility functions for enhancing your ImGui-based user interfaces.
 * This header file defines various functions for creating custom widgets and UI elements.
 *
 * @author LIBHHHH/N1kryyy
 * @date October 4, 2023
 */




#pragma once

#include <iostream>
#include <imgui.h>

#include <imgui_internal.h>

#include <chrono>

#include "Anim_Utils.h"

#include <time.h>




std::chrono::system_clock::time_point lastUpdateTime;
int currentSecond = -1;




	




namespace ImGuiX {
  

	
	void Switch(const char* label, bool* v)
{
    ImVec2 p = ImGui::GetCursorScreenPos();
    ImDrawList* draw_list = ImGui::GetWindowDrawList();
    ImGuiStyle& style = ImGui::GetStyle();

    float height = ImGui::GetFrameHeight();
    float width = height * 1.55f;
    float radius = height * 0.50f;

    ImGui::InvisibleButton(label, ImVec2(width, height));
    if (ImGui::IsItemClicked())
        *v = !*v;

    float t = *v ? 1.0f : 0.0f;

    ImGuiContext& g = *GImGui;
    float ANIM_SPEED = 0.08f;

    if (g.LastActiveId == g.CurrentWindow->GetID(label))
    {
        float t_anim = ImSaturate(g.LastActiveIdTimer / ANIM_SPEED);
        t = *v ? (t_anim) : (1.0f - t_anim);
    }

    ImU32 col_bg;
    if (ImGui::IsItemHovered())
        col_bg = ImGui::GetColorU32(ImLerp(style.Colors[ImGuiCol_FrameBgHovered], style.Colors[ImGuiCol_FrameBg], t));
    else
        col_bg = ImGui::GetColorU32(ImLerp(style.Colors[ImGuiCol_FrameBg], style.Colors[ImGuiCol_FrameBgActive], t));

    draw_list->AddRectFilled(p, ImVec2(p.x + width, p.y + height), col_bg, height * 0.5f);
    draw_list->AddCircleFilled(ImVec2(p.x + radius + t * (width - radius * 2.0f), p.y + radius), radius - 1.5f, IM_COL32(255, 255, 255, 255));

    ImGui::SameLine();
    ImGui::Text(label);
}
	
	// wait more 
	
	void Date()
{
  
    std::time_t currentTime = std::time(nullptr);
    std::tm* localTime = std::localtime(&currentTime);

    
    
    
    char dateString[12]; // YYYY-MM-DD + null-terminator
    std::strftime(dateString, sizeof(dateString), "%Y-%m-%d", localTime);

   
    ImGui::Text("Current Date: %s", dateString);
}


void XClock()
{

    std::time_t currentTime = std::time(nullptr);
    std::tm* localTime = std::localtime(&currentTime);


    int currentSec = localTime->tm_sec;

    if (currentSec != currentSecond)
    {
        lastUpdateTime = std::chrono::system_clock::now();
        currentSecond = currentSec;
    }


    auto now = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsedSeconds = now - lastUpdateTime;


    char timeString[9]; // HH:MM:SS + null-terminator
    std::strftime(timeString, sizeof(timeString), "%H:%M:%S", localTime);


    ImGui::Text("Current Time: %s", timeString);
    ImGui::Text("Elapsed Time: %.2f seconds", elapsedSeconds.count());
}
// Animation 
    void RainbowText(const char* text)
{
    ImVec4 rainbowColors[] = {
        ImVec4(1.0f, 0.0f, 0.0f, 1.0f),   
        ImVec4(1.0f, 0.5f, 0.0f, 1.0f),   
        ImVec4(1.0f, 1.0f, 0.0f, 1.0f), 
        ImVec4(0.0f, 1.0f, 0.0f, 1.0f), 
        ImVec4(0.0f, 0.0f, 1.0f, 1.0f),  
        ImVec4(0.5f, 0.0f, 0.5f, 1.0f)  
    };

    static float time = 0.0f;
    time += 0.01f;
    int colorIndex = int(time) % 6;
    float lerpFactor = time - int(time);

    ImVec4 color1 = rainbowColors[colorIndex];
    ImVec4 color2 = rainbowColors[(colorIndex + 1) % 6];

    ImVec4 lerpedColor;
    lerpedColor.x = color1.x + lerpFactor * (color2.x - color1.x);
    lerpedColor.y = color1.y + lerpFactor * (color2.y - color1.y);
    lerpedColor.z = color1.z + lerpFactor * (color2.z - color1.z);
    lerpedColor.w = color1.w + lerpFactor * (color2.w - color1.w);

    ImGui::TextColored(lerpedColor, text);

	}
	
	
// UnreleasedGuI::RainbowBegin("Window 1 with No Collapse", ImGuiWindowFlags_NoResize);


void RainbowBegin(const char* title, bool* v = nullptr, ImGuiWindowFlags flags = 0)
{
    ImVec4 rainbowColors[] = {
        ImVec4(1.0f, 0.0f, 0.0f, 1.0f),   
        ImVec4(1.0f, 0.5f, 0.0f, 1.0f),   
        ImVec4(1.0f, 1.0f, 0.0f, 1.0f),   
        ImVec4(0.0f, 1.0f, 0.0f, 1.0f),   
        ImVec4(0.0f, 0.0f, 1.0f, 1.0f),   
        ImVec4(0.5f, 0.0f, 0.5f, 1.0f)    
    };

    static float time = 0.0f;
    time += 0.01f;
    int colorIndex = int(time) % 6;
    float lerpFactor = time - int(time);

    ImVec4 color1 = rainbowColors[colorIndex];
    ImVec4 color2 = rainbowColors[(colorIndex + 1) % 6];

    ImVec4 lerpedColor;
    lerpedColor.x = color1.x + lerpFactor * (color2.x - color1.x);
    lerpedColor.y = color1.y + lerpFactor * (color2.y - color1.y);
    lerpedColor.z = color1.z + lerpFactor * (color2.z - color1.z);
    lerpedColor.w = color1.w + lerpFactor * (color2.w - color1.w);

    ImGui::PushStyleColor(ImGuiCol_Text, lerpedColor);
    ImGui::Begin(title, nullptr, flags);
    ImGui::PopStyleColor();



    
}
//Fps
void FpsTrack() {
    AnimUtil::UpdateDeltaTime();

    static float prevFps = 0.0f;
    float currentFps = 1.0f / AnimUtil::GetDeltaTime();

    ImVec4 color;

    if (currentFps >= 60.0f) {
        color = ImVec4(0.0f, 1.0f, 0.0f, 1.0f); 
    } else if (currentFps <= 30.0f) {
        color = ImVec4(1.0f, 0.0f, 0.0f, 1.0f); 
    } else {
        
        color = ImVec4(1.0f, 1.0f, 0.0f, 1.0f); ю
    }

    char fpsText[32];
    snprintf(fpsText, sizeof(fpsText), "FPS: %.1f", currentFps);
    ImVec2 position(50.0f, 70.0f);

    AnimUtil::DrawText2(40.0f, position, color, fpsText, false);

    prevFps = currentFps;
}






float cornerRadius = 0.0f;
bool showBorders = true;
ImVec4 backgroundColor = ImVec4(0.2f, 0.2f, 0.2f, 1.0f); 
float fontSize = 16.0f;
bool window_Editor = false;

bool sh = false;
bool fps = false;

void ShowDemoWindow(bool* v = nullptr) {

    ImGui::Begin("ImGuiX::SayHello!");
	ImGui::Text("ImGuiExtra Version 1.54 (Get Started)");
    if (ImGui::BeginTabBar("Functional")) {
        if (ImGui::BeginTabItem("functional")) {
            Switch("Show Demo Window", &sh);
            Switch("Show Fps", &fps);

            Switch("Test", &window_Editor);
			
            
            ImGui::EndTabItem();
        }

        if (ImGui::BeginTabItem("Clock_Wigets")) {
            
			Date();
            XClock();
            
            ImGui::EndTabItem();
			
        }
		if (ImGui::BeginTabItem("Rainbow Elements")) {
        
            RainbowText("HELLO WORLD!");

            ImGui::EndTabItem();
			}

        ImGui::EndTabBar();
    }
	

    ImGui::End();
	
	
	
if (sh){
	ImGui::ShowDemoWindow(&sh);
}
	if (fps){
		
		FpsTrack();
	}
	if (window_Editor){
		ImGuiX::RainbowBegin("Window Editor", &window_Editor);
	    if (ImGui::InputFloat("Radius", &cornerRadius, 1.0f, 10.0f)) {
        
    }

    
    if (ImGui::Checkbox("Show Border", &showBorders)) {
        
    }

    
    if (ImGui::ColorEdit3("Background Color", (float*)&backgroundColor)) {
        
    }

 
    if (ImGui::InputFloat("Font Size", &fontSize, 1.0f, 100.0f)) {
     
    }

  
    ImGuiStyle& style = ImGui::GetStyle();
    style.WindowRounding = cornerRadius;
    style.FrameRounding = cornerRadius;
    style.GrabRounding = cornerRadius;
    style.WindowBorderSize = showBorders ? 1.0f : 0.0f;

    
    ImGui::GetStyle().Colors[ImGuiCol_WindowBg] = backgroundColor;

    
    ImGui::GetIO().FontGlobalScale = fontSize / 16.0f;

   
    ImGui::End();

	}
	

}


}






            
                




