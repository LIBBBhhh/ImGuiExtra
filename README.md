# ImGuiExtra
 ImGuiExtra is a set of custom ImGui widgets and utility functions for enhancing your ImGui-based user interfaces.  This header file defines various functions for creating custom widgets and UI elements.
 ### START USAGE
 .mk template:
```makefile
LOCAL_C_INCLUDES += $(LOCAL_PATH)/src/ImGuiX/
LOCAL_SRC_FILES := \
   
    src/ImGuiX/ImGuiExtra.cpp \
  
```

### About of Update 1.61

1.Added vertical float slider 




Usage: 
```C++
ImGuiX::VerticalSliderFloat("Float", ImVec2(50, 100),  &floaaa, 1.5f, 50.0f);
```

Or announce the function to them and use it on all sliders

```С++
ImVec2 sizecfg = ImVec2(50, 100);
ImGuiX::VerticalSliderFloat("Float", sizecfg,  &floaaa, 1.5f, 50.0f);
```









2. Custom Hints 


Usage:
```C++
ImGuiX::HelpMarker("ImGuiExtra Ver:", IMGUIX_VERSION, 60.1f);
```
In this case, the font width where IMGUIX VERSION will be 60.1 float and the first is the text, say the label in front of the button 


```C++
ImGuiX::HelpMarker("ImGuiExtra Ver:", "Uninfo", 60.1f);
```



### Issues 

write ideas for adding something, etc. to issues for developers, if you have posted anything with my utility, please indicate this repository








### suppotrted version imgui
1.84 Wip and higher




### examples 
```C++
ImGuiX::Switch("print", &bool);
```


```C++
ImGuiX::RainbowText("print");

```

```C++
ImGuiX::RainbowBegin("print", flags);
```



### demo window
```C++
ImGuiX::ShowDemoWindow();
```
