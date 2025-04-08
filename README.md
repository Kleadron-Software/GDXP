# Archival Notice
I currently have little interest in maintaining this right now. 
I'll archive this but keep it public for anyone else interested in using it, either for basing their own project off of or for learning from.
There may be a day I return to this.

## GDXP - What is this?

![Screenshot of a 3D scene in the GDXP editor](/editor_screenshot.png)

GDXP is a fork of Godot 2.1.7 RC that targets legacy Windows for fun, and implements an OpenGL 1.x compatible renderer.  
**GDXP is unofficial and not affiliated with the Godot project.**  
If you're looking for the regular version of Godot, you can find it here: https://godotengine.org

The lowest platform target is currently 32-bit Windows XP, but the GLES1 rasterizer should be portable to other platforms that implement OpenGL.
I only develop on Windows, so I have not explored other platforms.  
"GDXP" is kind of a temporary name but I have nothing better.

You can check what I've done so far and what I have in mind here:  
[Changelog](/xp_changes.md)  
[Ideas/Plans](/xp_ideas.md)  

#### Can I use this to load existing games?

This version of Godot is not intended as an engine replacement for existing Godot 2 games, and is an enthusiast version made for my own purposes.
There are changes backported from Godot 3 and 4 that fundamentally make this version incompatible with unmodified Godot 2 projects.  

Existing games target the GLES2 renderer, but this fork uses the GLES1 renderer by default for compatibility reasons.  
If you load a GD2 project in this, it might not look correct without tweaking the video driver setting.  

#### Should I use this over regular/modern Godot?

No, you shouldn't.  
As stated above, this is my own enthusiast version of the engine. I currently do not have any documentation set up aside from documented changes.  
The source code of this project is available publicly as I do not see a benefit in keeping it closed-source.  

I don't mind it if someone wants to use this version, as long as you understand what you're getting, but you'll get way better support if you use a newer Godot version like 3.x or 4.x.

Keep in mind that Godot 2 was built from already outdated technology, and the workflow isn't the same as a modern engine.  
I backport some optimizations I can, if applicable, but optimization still needs to be taken into account.

#### Important Notes

- I compile this using Visual C++ Express 2010's toolset.
- Some of the editor GUI is modified to be more usable on low-res screens.
- The current OpenGL 1.x compatible renderer is labled as the GLES1 renderer as that was the name inherited from Godot 1.0.
  This name is potentially misleading since I am targeting the regular OpenGL spec.
- Some of the functions used in the renderer suggest a minimum OpenGL version of 1.5.
  Buffer objects (1.5) and multitexturing features (1.3) are used.
  I might add a way for the engine to detect if these features are available so it can run on lower versions.
- NO_THREADING is defined as there is no InterlockedCompareExchange64 function on NT 5.1 (Windows XP 32-bit).
  I don't know the full concequences of this but things seem to work fine, so, /shrug.
  This also means light baking may be broken.
- Sphere mapping looks different between GLES1 and GLES2 since GLES1 uses the texgen of OpenGL, while GLES2 uses a different technique.
  Textures used with texgen sphere mapping are also upside down.
- Meshes that use vertex colors alongside features like Lighting do not work. Need to explore GL_COLOR_MATERIAL.

#### GLES1 Known limitations

- Certain editor gizmos and vertex colored meshes render as white.
- Viewports do not render correctly in the editor, and escape the main viewport.
  The engine expects the editor viewport to use a framebuffer object, but FBOs are not implemented for the GLES1 renderer at the moment.
- Render targets/viewport textures especially do not work.
- Texture/cubemap environment background does not work.
- Not all FixedMaterial features work. FixedMaterials can only render using one texture at a time
  as their material properties are fed to the OpenGL fixed function lighting material system.
  This causes differences in rendering. Since the fixed-function pipeline lighting is vertex-based,
  material features like Emission will add color to the mesh vertices rather than the result of a texture to the surface.
  The GLES2 renderer allows you to select textures for features like specular/bump/emission, but in the GLES1 renderer
  these are treated as vertex lighting modifiers.
- ShaderMaterials and Shaders do not work AT ALL. This would require OpenGL extensions to support.

#### Attributions

This software uses portions of [Godot 3](https://github.com/godotengine/godot/tree/3.x) source code.  
As it is impossible for me to individually credit every contributor's line of code that I've used, I decided to include the full contributor's list.  
I have also updated the visible copyright dates to match Godot 3's.  
I've done my best to attribute them correctly. I'm not a legal expert, so if I've made a mistake, create an issue about it and we can work it out.
