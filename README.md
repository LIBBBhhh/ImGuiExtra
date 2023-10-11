# ImGuiExtra
 ImGuiExtra is a set of custom ImGui widgets and utility functions for enhancing your ImGui-based user interfaces.  This header file defines various functions for creating custom widgets and UI elements.


### About of Update 1.61

1.Added vertical float slider 




Usage: 
```
ImGuiX::VerticalSliderFloat("Float", ImVec2(50, 100),  &floaaa, 1.5f, 50.0f);
```

Or announce the function to them and use it on all sliders

```С++
ImVec2 sizecfg = ImVec2(50, 100);
ImGuiX::VerticalSliderFloat("Float", sizecfg,  &floaaa, 1.5f, 50.0f);
```









2. Custom Hints 


Usage:
```
ImGuiX::HelpMarker("ImGuiExtra Ver:", IMGUIX_VERSION, 60.1f);
```
In this case, the font width where IMGUIX VERSION will be 60.1 float and the first is the text, say the label in front of the button 


```
ImGuiX::HelpMarker("ImGuiExtra Ver:", "Uninfo", 60.1f);
```



### Issues 

write ideas for adding something, etc. to issues for developers, if you have posted anything with my utility, please indicate this repository



### what do you need to know?
the fact that there is also a file with utilities without it will not start and will not work fortunately the file is already included in cpp, just include it in your main or menu 





### suppotrted version imgui
1.84 Wip and higher




### examples 
```
ImGuiX::Switch("print", &bool);
```


```
ImGuiX::RainbowText("print");

```

```
ImGuiX::RainbowBegin("print", flags);
```



### demo window
```
ImGuiX::ShowDemoWindow();
```
