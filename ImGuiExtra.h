//
// Doc: Use This File For Include This In your Draw. From version 1.62
//


namespace ImGuiX {
	// 1.62
    void CenteredText(const char* text);
    
    void SetAccentColor(const ImColor& newColor);

void SetStyleAccentColor(const ImVec4& color);

    bool TabButton(const char* label, bool selected, const ImVec2& size);
    
    void NeonLineAnimation();
    
    void Line(ImColor color);
    
    void LineRed();
    
    void RainbowAnimationLine(float thickness);
    
    // 1.60-1.61
 bool VerticalSliderFloat(const char* label, const ImVec2& size, float* v, float v_min, float v_max);

 static void HelpMarker(const char* label, const char* desc, float fontSize);


 void Switch(const char* label, bool* v);


 void Date();

 void XClock();

 void RainbowText(const char* text);



 void RainbowBegin(const char* title, bool* p_opn = nullptr, ImGuiWindowFlags flags = 0);


 void FpsTrack();

 void ShowDemoWindow(bool* v = nullptr);  


}


