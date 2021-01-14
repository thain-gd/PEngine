### Notes:
* The editor can only run on Windows.
* The editor can only render flat color quads.
* You need a graphics card that supports OpenGL 4.5 or above to run the editor.
* Runtime cameras are currently not supported while using the editor camera.

### How to run the editor
* **NVIDIA:** Right-click `PEngine-Editor.exe`, select `Run with graphics processor`, and select `High-performance NVIDIA processor`.

### Usages
* **Create entities:** Right-click in Scene Hierarchy to create an entity.
* **Create a sprite**:
 1. Create an empty entity.
 2. In Properties panel, select `Add Component` to add a sprite renderer.
   * You can then select the color of the sprite.
* **Delete entities:**
  * Right-click an entity and select `Delete Entity`.
  * Select an entity and press Delete key.
* **Gizmos Hotkeys:**
  * Q: Disable
  * W: Translation
  * E: Rotation
  * R: Scale
* **Editor Camera Hotkeys:**
  * `Alt` + `Left Mouse`: Rotation
  * `Alt` + `Middle Mouse`: Translation
  * `Alt` + `Right Mouse` or `Mouse Scroll`: Scale
* **Checking benchmarks**:
  1. Open Google Chrome.
  2. Enter `chrome://tracing`
  3. Drag JSON files generated within the folder contains the `PEngine-Editor.exe` into Chrome.
