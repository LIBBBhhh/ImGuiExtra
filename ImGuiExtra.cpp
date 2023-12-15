// ImGuiExtra Version 1.61

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
 * @Creation Date October 4, 2023
 * @Update Date 11.21.23
 */





#include <iostream>
#include <imgui.h>

#include <imgui_internal.h>

#include <chrono>

#include "Anim_Utils.h"

#include "ImGuiExtra.h"
#include <time.h>

#define ImGuiX_Version "1.61"

#define VERSION_CODE "745879"

std::chrono::system_clock::time_point lastUpdateTime;
int currentSecond = -1;



// Switch taken from -> https://github.com/ocornut/imgui/issues/1537#issuecomment-355562097
	





  
bool ImGuiX::VerticalSliderFloat(const char* label, const ImVec2& size, float* v, float v_min, float v_max)
{
    ImGui::PushID(label);
    
 
    ImVec2 pos = ImGui::GetCursorScreenPos();
    ImGui::InvisibleButton(label, size);
    if (ImGui::IsItemActive())
    {
        
        ImGui::SetTooltip("%.3f", *v);
        float delta = ImGui::GetIO().MouseDelta.y;
        float range = v_max - v_min;
        *v -= (delta / size.y) * range;
        *v = ImClamp(*v, v_min, v_max);
    }

 
    ImGui::GetWindowDrawList()->AddRectFilled(pos, ImVec2(pos.x + size.x, pos.y + size.y), ImGui::GetColorU32(ImGuiCol_FrameBg));

    
    float fraction = 1.0f - (*v - v_min) / (v_max - v_min);
    
    float knobPosY = fraction * (size.y - size.x) + size.x / 2; 

  
    ImGui::GetWindowDrawList()->AddRectFilled(ImVec2(pos.x, pos.y + knobPosY - size.x/2), 
                                              ImVec2(pos.x + size.x, pos.y + knobPosY + size.x/2), 
                                              ImGui::GetColorU32(ImGuiCol_SliderGrabActive));

    

    ImGui::SameLine();
    ImGui::Text(label);

    ImGui::PopID();
    
    return ImGui::IsItemDeactivatedAfterEdit();
}





	static void ImGuiX::HelpMarker(const char* label, const char* desc, float fontSize)
{
	ImGui::Text(label);
	ImGui::SameLine();
    ImGui::TextDisabled("(?)");
    if (ImGui::IsItemHovered())
    {
        ImGui::BeginTooltip();
        ImGui::PushTextWrapPos(ImGui::GetFontSize() * fontSize);
        ImGui::TextUnformatted(desc);
        ImGui::PopTextWrapPos();
        ImGui::EndTooltip();
    }
}
	
	
	void ImGuiX::Switch(const char* label, bool* v)
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
	
	void ImGuiX::Date()
{
  
    std::time_t currentTime = std::time(nullptr);
    std::tm* localTime = std::localtime(&currentTime);

    
    
    
    char dateString[12]; // YYYY-MM-DD + null-terminator
    std::strftime(dateString, sizeof(dateString), "%Y-%m-%d", localTime);

   
    ImGui::Text("Current Date: %s", dateString);
}


void ImGuiX::XClock()
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
    void ImGuiX::RainbowText(const char* text)
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


void ImGuiX::RainbowBegin(const char* title, bool* p_opn, ImGuiWindowFlags flags)

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
    ImGui::Begin(title, p_opn, flags);
    ImGui::PopStyleColor();



    
}
//Fps
void ImGuiX::FpsTrack() {
    AnimUtil::UpdateDeltaTime();

    static float prevFps = 0.0f;
    float currentFps = 1.0f / AnimUtil::GetDeltaTime();

    ImVec4 color;

    if (currentFps >= 60.0f) {
        color = ImVec4(0.0f, 1.0f, 0.0f, 1.0f); 
    } else if (currentFps <= 30.0f) {
        color = ImVec4(1.0f, 0.0f, 0.0f, 1.0f); 
    } else {
        
        color = ImVec4(1.0f, 1.0f, 0.0f, 1.0f); 
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
float floaaa = 1.5;
bool window_Editor = false;
ImVec2 sizecfg = ImVec2(50, 100);
int sis = 20;
bool sh = false;
bool fps = false;

void ImGuiX::ShowDemoWindow(bool* v) {

    ImGui::Begin("ImGuiX::SayHello!");
	ImGuiX::HelpMarker("ImGuiExtra Ver: b%", ImGuiX_Version, 60.1f);
    if (ImGui::BeginTabBar("Functional")) {
        if (ImGui::BeginTabItem("functional")) {
           ImGuiX::Switch("Show Demo Window", &sh);
           ImGuiX::Switch("Show Fps", &fps);

           ImGuiX::Switch("Test", &window_Editor);
			ImGuiX::VerticalSliderFloat("Float", sizecfg,  &floaaa, 1.5f, 50.0f);

            ImGui::EndTabItem();
        }

        if (ImGui::BeginTabItem("Clock_Wigets")) {
            
			ImGuiX::Date();
            ImGuiX::XClock();
            
            ImGui::EndTabItem();
			
        }
		if (ImGui::BeginTabItem("Rainbow Elements")) {
        
            ImGuiX::RainbowText("HELLO WORLD!");

            ImGui::EndTabItem();
			}

        ImGui::EndTabBar();
    }
	

    ImGui::End();
	
	
	
if (sh){
	ImGui::ShowDemoWindow(&sh);
}
	if (fps){
		
		ImGuiX::FpsTrack();
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














          
                




