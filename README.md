# ImGuiExtra
 ImGuiExtra is a set of custom ImGui widgets and utility functions for enhancing your ImGui-based user interfaces.  This header file defines various functions for creating custom widgets and UI elements.


###About of Update 

1.Added vertical float slider 
https://media.discordapp.net/attachments/1161660501185544204/1161736145672081518/Screenrecorder-2023-10-11-22-28-17-9940.mp4?ex=65396219&is=6526ed19&hm=3959ad74d1968dccf99cbf66d15cdb9535ecf448d418fc9e2856e0beda9f0d91&



Usage: 

ImGuiX::VerticalSliderFloat("Float", ImVec2(50, 100),  &floaaa, 1.5f, 50.0f);

Or announce the function to them and use it on all sliders

ImVec2 sizecfg = ImVec2(50, 100);
ImGuiX::VerticalSliderFloat("Float", sizecfg,  &floaaa, 1.5f, 50.0f);










2. Custom Hints 
https://media.discordapp.net/attachments/1161660501185544204/1161735714896097341/Screenrecorder-2023-10-11-22-28-53-4340.mp4?ex=653961b2&is=6526ecb2&hm=d58ef659f9004e06400e87d0dc88704a63bfe32c013f1cdb0e1e3cef75771eb7&

Usage:

ImGuiX::HelpMarker("ImGuiExtra Ver:", IMGUIX_VERSION, 60.1f);


In this case, the font width where IMGUIX VERSION will be 60.1 float and the first is the text, say the label in front of the button 



ImGuiX::HelpMarker("ImGuiExtra Ver:", "Uninfo", 60.1f);




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
