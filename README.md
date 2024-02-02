# ImGuiExtra
 ImGuiExtra is a set of custom ImGui widgets and utility functions for enhancing your ImGui-based user interfaces.  This header file defines various functions for creating custom widgets and UI elements.


https://github.com/LIBBBhhh/ImGuiExtra/blob/main/Prew/IMG_1071.MOV

 
 ### START USAGE
 .mk template(FOR ANDROID):
```makefile
LOCAL_C_INCLUDES += $(LOCAL_PATH)/src/ImGuiX/
LOCAL_SRC_FILES := \
   
    src/ImGuiX/ImGuiExtra.cpp \
  
```

### About of Update 1.62

1.Added tabs
2. lines 
3. centred text



### Issues 

write ideas for adding something, etc. to issues for developers, if you have posted anything with my utility, please indicate this repository








### suppotrted version imgui
1.62 Wip and higher




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
