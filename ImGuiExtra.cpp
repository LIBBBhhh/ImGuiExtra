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
