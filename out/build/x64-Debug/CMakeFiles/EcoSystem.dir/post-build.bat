@echo off
cd /D E:\Projects\GitHub\DS_homework\out\build\x64-Debug || (set FAIL_LINE=2& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E echo "copy dll into target file dir: uv.dll ..." || (set FAIL_LINE=3& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E copy_if_different E:/Projects/GitHub/DS_homework/cocos2d/external/uv/prebuilt/win32/uv.dll E:/Projects/GitHub/DS_homework/out/build/x64-Debug/bin/EcoSystem/uv.dll || (set FAIL_LINE=4& goto :ABORT)
cd /D E:\Projects\GitHub\DS_homework\out\build\x64-Debug || (set FAIL_LINE=5& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E echo "copy dll into target file dir: libssl-1_1.dll ..." || (set FAIL_LINE=6& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E copy_if_different E:/Projects/GitHub/DS_homework/cocos2d/external/openssl/prebuilt/win32/libssl-1_1.dll E:/Projects/GitHub/DS_homework/out/build/x64-Debug/bin/EcoSystem/libssl-1_1.dll || (set FAIL_LINE=7& goto :ABORT)
cd /D E:\Projects\GitHub\DS_homework\out\build\x64-Debug || (set FAIL_LINE=8& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E echo "copy dll into target file dir: libcrypto-1_1.dll ..." || (set FAIL_LINE=9& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E copy_if_different E:/Projects/GitHub/DS_homework/cocos2d/external/openssl/prebuilt/win32/libcrypto-1_1.dll E:/Projects/GitHub/DS_homework/out/build/x64-Debug/bin/EcoSystem/libcrypto-1_1.dll || (set FAIL_LINE=10& goto :ABORT)
cd /D E:\Projects\GitHub\DS_homework\out\build\x64-Debug || (set FAIL_LINE=11& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E echo "copy dll into target file dir: websockets.dll ..." || (set FAIL_LINE=12& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E copy_if_different E:/Projects/GitHub/DS_homework/cocos2d/external/websockets/prebuilt/win32/websockets.dll E:/Projects/GitHub/DS_homework/out/build/x64-Debug/bin/EcoSystem/websockets.dll || (set FAIL_LINE=13& goto :ABORT)
cd /D E:\Projects\GitHub\DS_homework\out\build\x64-Debug || (set FAIL_LINE=14& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E echo "copy dll into target file dir: libcurl.dll ..." || (set FAIL_LINE=15& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E copy_if_different E:/Projects/GitHub/DS_homework/cocos2d/external/curl/prebuilt/win32/libcurl.dll E:/Projects/GitHub/DS_homework/out/build/x64-Debug/bin/EcoSystem/libcurl.dll || (set FAIL_LINE=16& goto :ABORT)
cd /D E:\Projects\GitHub\DS_homework\out\build\x64-Debug || (set FAIL_LINE=17& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E echo "copy dll into target file dir: sqlite3.dll ..." || (set FAIL_LINE=18& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E copy_if_different E:/Projects/GitHub/DS_homework/cocos2d/external/sqlite3/libraries/win32/sqlite3.dll E:/Projects/GitHub/DS_homework/out/build/x64-Debug/bin/EcoSystem/sqlite3.dll || (set FAIL_LINE=19& goto :ABORT)
cd /D E:\Projects\GitHub\DS_homework\out\build\x64-Debug || (set FAIL_LINE=20& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E echo "copy dll into target file dir: glew32.dll ..." || (set FAIL_LINE=21& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E copy_if_different E:/Projects/GitHub/DS_homework/cocos2d/external/win32-specific/gles/prebuilt/glew32.dll E:/Projects/GitHub/DS_homework/out/build/x64-Debug/bin/EcoSystem/glew32.dll || (set FAIL_LINE=22& goto :ABORT)
cd /D E:\Projects\GitHub\DS_homework\out\build\x64-Debug || (set FAIL_LINE=23& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E echo "copy dll into target file dir: iconv.dll ..." || (set FAIL_LINE=24& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E copy_if_different E:/Projects/GitHub/DS_homework/cocos2d/external/win32-specific/icon/prebuilt/iconv.dll E:/Projects/GitHub/DS_homework/out/build/x64-Debug/bin/EcoSystem/iconv.dll || (set FAIL_LINE=25& goto :ABORT)
cd /D E:\Projects\GitHub\DS_homework\out\build\x64-Debug || (set FAIL_LINE=26& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E echo "copy dll into target file dir: libmpg123.dll ..." || (set FAIL_LINE=27& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E copy_if_different E:/Projects/GitHub/DS_homework/cocos2d/external/win32-specific/MP3Decoder/prebuilt/libmpg123.dll E:/Projects/GitHub/DS_homework/out/build/x64-Debug/bin/EcoSystem/libmpg123.dll || (set FAIL_LINE=28& goto :ABORT)
cd /D E:\Projects\GitHub\DS_homework\out\build\x64-Debug || (set FAIL_LINE=29& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E echo "copy dll into target file dir: libogg.dll ..." || (set FAIL_LINE=30& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E copy_if_different E:/Projects/GitHub/DS_homework/cocos2d/external/win32-specific/OggDecoder/prebuilt/libogg.dll E:/Projects/GitHub/DS_homework/out/build/x64-Debug/bin/EcoSystem/libogg.dll || (set FAIL_LINE=31& goto :ABORT)
cd /D E:\Projects\GitHub\DS_homework\out\build\x64-Debug || (set FAIL_LINE=32& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E echo "copy dll into target file dir: libvorbis.dll ..." || (set FAIL_LINE=33& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E copy_if_different E:/Projects/GitHub/DS_homework/cocos2d/external/win32-specific/OggDecoder/prebuilt/libvorbis.dll E:/Projects/GitHub/DS_homework/out/build/x64-Debug/bin/EcoSystem/libvorbis.dll || (set FAIL_LINE=34& goto :ABORT)
cd /D E:\Projects\GitHub\DS_homework\out\build\x64-Debug || (set FAIL_LINE=35& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E echo "copy dll into target file dir: libvorbisfile.dll ..." || (set FAIL_LINE=36& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E copy_if_different E:/Projects/GitHub/DS_homework/cocos2d/external/win32-specific/OggDecoder/prebuilt/libvorbisfile.dll E:/Projects/GitHub/DS_homework/out/build/x64-Debug/bin/EcoSystem/libvorbisfile.dll || (set FAIL_LINE=37& goto :ABORT)
cd /D E:\Projects\GitHub\DS_homework\out\build\x64-Debug || (set FAIL_LINE=38& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E echo "copy dll into target file dir: OpenAL32.dll ..." || (set FAIL_LINE=39& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E copy_if_different E:/Projects/GitHub/DS_homework/cocos2d/external/win32-specific/OpenalSoft/prebuilt/OpenAL32.dll E:/Projects/GitHub/DS_homework/out/build/x64-Debug/bin/EcoSystem/OpenAL32.dll || (set FAIL_LINE=40& goto :ABORT)
cd /D E:\Projects\GitHub\DS_homework\out\build\x64-Debug || (set FAIL_LINE=41& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E echo "copy dll into target file dir: zlib1.dll ..." || (set FAIL_LINE=42& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E copy_if_different E:/Projects/GitHub/DS_homework/cocos2d/external/zlib/../win32-specific/zlib/prebuilt/zlib1.dll E:/Projects/GitHub/DS_homework/out/build/x64-Debug/bin/EcoSystem/zlib1.dll || (set FAIL_LINE=43& goto :ABORT)
cd /D E:\Projects\GitHub\DS_homework\out\build\x64-Debug || (set FAIL_LINE=44& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E echo "copy file into Resources: CloseNormal.png ..." || (set FAIL_LINE=45& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E copy_if_different E:/Projects/GitHub/DS_homework/Resources/CloseNormal.png E:/Projects/GitHub/DS_homework/out/build/x64-Debug/bin/EcoSystem/Resources/CloseNormal.png || (set FAIL_LINE=46& goto :ABORT)
cd /D E:\Projects\GitHub\DS_homework\out\build\x64-Debug || (set FAIL_LINE=47& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E echo "copy file into Resources: CloseSelected.png ..." || (set FAIL_LINE=48& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E copy_if_different E:/Projects/GitHub/DS_homework/Resources/CloseSelected.png E:/Projects/GitHub/DS_homework/out/build/x64-Debug/bin/EcoSystem/Resources/CloseSelected.png || (set FAIL_LINE=49& goto :ABORT)
cd /D E:\Projects\GitHub\DS_homework\out\build\x64-Debug || (set FAIL_LINE=50& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E echo "copy file into Resources: HelloWorld.png ..." || (set FAIL_LINE=51& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E copy_if_different E:/Projects/GitHub/DS_homework/Resources/HelloWorld.png E:/Projects/GitHub/DS_homework/out/build/x64-Debug/bin/EcoSystem/Resources/HelloWorld.png || (set FAIL_LINE=52& goto :ABORT)
cd /D E:\Projects\GitHub\DS_homework\out\build\x64-Debug || (set FAIL_LINE=53& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E echo "copy file into Resources: SliderNode_Disable.png ..." || (set FAIL_LINE=54& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E copy_if_different E:/Projects/GitHub/DS_homework/Resources/SliderNode_Disable.png E:/Projects/GitHub/DS_homework/out/build/x64-Debug/bin/EcoSystem/Resources/SliderNode_Disable.png || (set FAIL_LINE=55& goto :ABORT)
cd /D E:\Projects\GitHub\DS_homework\out\build\x64-Debug || (set FAIL_LINE=56& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E echo "copy file into Resources: SliderNode_Normal.png ..." || (set FAIL_LINE=57& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E copy_if_different E:/Projects/GitHub/DS_homework/Resources/SliderNode_Normal.png E:/Projects/GitHub/DS_homework/out/build/x64-Debug/bin/EcoSystem/Resources/SliderNode_Normal.png || (set FAIL_LINE=58& goto :ABORT)
cd /D E:\Projects\GitHub\DS_homework\out\build\x64-Debug || (set FAIL_LINE=59& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E echo "copy file into Resources: SliderNode_Press.png ..." || (set FAIL_LINE=60& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E copy_if_different E:/Projects/GitHub/DS_homework/Resources/SliderNode_Press.png E:/Projects/GitHub/DS_homework/out/build/x64-Debug/bin/EcoSystem/Resources/SliderNode_Press.png || (set FAIL_LINE=61& goto :ABORT)
cd /D E:\Projects\GitHub\DS_homework\out\build\x64-Debug || (set FAIL_LINE=62& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E echo "copy file into Resources: Slider_Back.png ..." || (set FAIL_LINE=63& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E copy_if_different E:/Projects/GitHub/DS_homework/Resources/Slider_Back.png E:/Projects/GitHub/DS_homework/out/build/x64-Debug/bin/EcoSystem/Resources/Slider_Back.png || (set FAIL_LINE=64& goto :ABORT)
cd /D E:\Projects\GitHub\DS_homework\out\build\x64-Debug || (set FAIL_LINE=65& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E echo "copy file into Resources: Slider_PressBar.png ..." || (set FAIL_LINE=66& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E copy_if_different E:/Projects/GitHub/DS_homework/Resources/Slider_PressBar.png E:/Projects/GitHub/DS_homework/out/build/x64-Debug/bin/EcoSystem/Resources/Slider_PressBar.png || (set FAIL_LINE=67& goto :ABORT)
cd /D E:\Projects\GitHub\DS_homework\out\build\x64-Debug || (set FAIL_LINE=68& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E echo "copy file into Resources: backgroundmap.tmx ..." || (set FAIL_LINE=69& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E copy_if_different E:/Projects/GitHub/DS_homework/Resources/backgroundmap.tmx E:/Projects/GitHub/DS_homework/out/build/x64-Debug/bin/EcoSystem/Resources/backgroundmap.tmx || (set FAIL_LINE=70& goto :ABORT)
cd /D E:\Projects\GitHub\DS_homework\out\build\x64-Debug || (set FAIL_LINE=71& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E echo "copy file into Resources: fonts/Marker Felt.ttf ..." || (set FAIL_LINE=72& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E copy_if_different "E:/Projects/GitHub/DS_homework/Resources/fonts/Marker Felt.ttf" "E:/Projects/GitHub/DS_homework/out/build/x64-Debug/bin/EcoSystem/Resources/fonts/Marker Felt.ttf" || (set FAIL_LINE=73& goto :ABORT)
cd /D E:\Projects\GitHub\DS_homework\out\build\x64-Debug || (set FAIL_LINE=74& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E echo "copy file into Resources: fonts/arial.ttf ..." || (set FAIL_LINE=75& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E copy_if_different E:/Projects/GitHub/DS_homework/Resources/fonts/arial.ttf E:/Projects/GitHub/DS_homework/out/build/x64-Debug/bin/EcoSystem/Resources/fonts/arial.ttf || (set FAIL_LINE=76& goto :ABORT)
cd /D E:\Projects\GitHub\DS_homework\out\build\x64-Debug || (set FAIL_LINE=77& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E echo "copy file into Resources: grass.jpg ..." || (set FAIL_LINE=78& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E copy_if_different E:/Projects/GitHub/DS_homework/Resources/grass.jpg E:/Projects/GitHub/DS_homework/out/build/x64-Debug/bin/EcoSystem/Resources/grass.jpg || (set FAIL_LINE=79& goto :ABORT)
cd /D E:\Projects\GitHub\DS_homework\out\build\x64-Debug || (set FAIL_LINE=80& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E echo "copy file into Resources: land.jpg ..." || (set FAIL_LINE=81& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E copy_if_different E:/Projects/GitHub/DS_homework/Resources/land.jpg E:/Projects/GitHub/DS_homework/out/build/x64-Debug/bin/EcoSystem/Resources/land.jpg || (set FAIL_LINE=82& goto :ABORT)
cd /D E:\Projects\GitHub\DS_homework\out\build\x64-Debug || (set FAIL_LINE=83& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E echo "copy file into Resources: map.png ..." || (set FAIL_LINE=84& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E copy_if_different E:/Projects/GitHub/DS_homework/Resources/map.png E:/Projects/GitHub/DS_homework/out/build/x64-Debug/bin/EcoSystem/Resources/map.png || (set FAIL_LINE=85& goto :ABORT)
cd /D E:\Projects\GitHub\DS_homework\out\build\x64-Debug || (set FAIL_LINE=86& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E echo "copy file into Resources: newMap.tmx ..." || (set FAIL_LINE=87& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E copy_if_different E:/Projects/GitHub/DS_homework/Resources/newMap.tmx E:/Projects/GitHub/DS_homework/out/build/x64-Debug/bin/EcoSystem/Resources/newMap.tmx || (set FAIL_LINE=88& goto :ABORT)
cd /D E:\Projects\GitHub\DS_homework\out\build\x64-Debug || (set FAIL_LINE=89& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E echo "copy file into Resources: panelbg.png ..." || (set FAIL_LINE=90& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E copy_if_different E:/Projects/GitHub/DS_homework/Resources/panelbg.png E:/Projects/GitHub/DS_homework/out/build/x64-Debug/bin/EcoSystem/Resources/panelbg.png || (set FAIL_LINE=91& goto :ABORT)
cd /D E:\Projects\GitHub\DS_homework\out\build\x64-Debug || (set FAIL_LINE=92& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E echo "copy file into Resources: res/.gitkeep ..." || (set FAIL_LINE=93& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E copy_if_different E:/Projects/GitHub/DS_homework/Resources/res/.gitkeep E:/Projects/GitHub/DS_homework/out/build/x64-Debug/bin/EcoSystem/Resources/res/.gitkeep || (set FAIL_LINE=94& goto :ABORT)
cd /D E:\Projects\GitHub\DS_homework\out\build\x64-Debug || (set FAIL_LINE=95& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E echo "copy file into Resources: tiles.tsx ..." || (set FAIL_LINE=96& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E copy_if_different E:/Projects/GitHub/DS_homework/Resources/tiles.tsx E:/Projects/GitHub/DS_homework/out/build/x64-Debug/bin/EcoSystem/Resources/tiles.tsx || (set FAIL_LINE=97& goto :ABORT)
cd /D E:\Projects\GitHub\DS_homework\out\build\x64-Debug || (set FAIL_LINE=98& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E echo "copy file into Resources: white.png ..." || (set FAIL_LINE=99& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E copy_if_different E:/Projects/GitHub/DS_homework/Resources/white.png E:/Projects/GitHub/DS_homework/out/build/x64-Debug/bin/EcoSystem/Resources/white.png || (set FAIL_LINE=100& goto :ABORT)
cd /D E:\Projects\GitHub\DS_homework\out\build\x64-Debug || (set FAIL_LINE=101& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E echo "copy file into Resources: wolf.png ..." || (set FAIL_LINE=102& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E copy_if_different E:/Projects/GitHub/DS_homework/Resources/wolf.png E:/Projects/GitHub/DS_homework/out/build/x64-Debug/bin/EcoSystem/Resources/wolf.png || (set FAIL_LINE=103& goto :ABORT)
goto :EOF

:ABORT
set ERROR_CODE=%ERRORLEVEL%
echo Batch file failed at line %FAIL_LINE% with errorcode %ERRORLEVEL%
exit /b %ERROR_CODE%