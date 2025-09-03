# UmbraFramework for Stellar Blade

This framework is a personal modding project. UmbraFramework aims to provide a way to allow users to install endless amount of skins to their games while only replacing the default suit as well as provide an easy way for modders to create and integrate their outfits to the Framework.
An Unreal project template is provided with various outfit setup examples.
The framework also provides an easy way to configure outfit customization for users to play around with. This includes color edits, visibility edits (hidding material sections), sliders (morphs/bone scaling), and material scalar parameters. This editing system can be used on any part of the framework; This includes, but is not limited to: base body, head, hair, accessory, etc...
Providing a wide range of customization to the user.

The framework template includes some Unreal Editor tutorials that will explain some of the basics on how to setup your mods using this framework.

This framework is made public to serve as knowledge base and a base for other users to extend and improve upon this framework.

> [!NOTE]
> By using this framework, it is assumed that you have minimal knowledge on: Unreal Engine, C++, Blueprints, modding with Unreal Engine, Programming in general, Blueprint data types and communication.

> [!NOTE]
> This framework is not perfect nor complete. Some bugs still exist within the codebase and the code isn't the cleanest code you'll ever see.

> [!IMPORTANT]
> This framework has not yet been tested with the most recent version of the game. 

## Setup

Umbra framework aims to be easy to use and install for **modders** and **users** as well as being as stable as possible across game updates. For this reason the **framework template** is **Blueprint Only**. The stability and ease of use comes at the cost of flexibility and the limitations of Blueprints.

> [!WARNING]
> Although the template is Blueprint Only, a C++ compiler is still required to compile the engine plugins.
> The user does not need to interact with any C++, only the compiler is needed

The **UmbraFramework** itself, is a separate project. It contains all the logic of the framework and a full C++ setup is required. This project references C++ boilerplate generated using UE4SS.

To setup visual studio for unreal engine, you can [visit this website](https://dev.epicgames.com/documentation/en-us/unreal-engine/setting-up-visual-studio-for-unreal-engine?application_version=4.27).

### UmbraFramework

- The folder `UmbraFramework` contains the Unreal Engine project for the base framework, mainly intended for people who want to modify or extend the framework
- If the framework is to be extended or modified, make sure to update the template project and notify the users of your modified version of this framework

### UmbraFrameworkProjectTemplate

- The folder `UmbraFrameworkProjectTemplate` contains the Unreal Engine project tempalte for using the UmbraFramework, mainly intended for modders who want make mods using the UmbraFramework
- The project contains a working version of `kawaii physics` (working in game and preview in editor) with an example outfit that makes use of it

## Features

| FEATURE                              | IMPLEMENTED? |
|:-------------------------------------|:------------:|
| Support large  amounts of skins      |      ✔️      |
| Custom rigs                          |      ✔️      |
| Custom materials                     |      ✔️      |
| Outfit customization                 |      ✔️      |
| Head/hair/accessories swapping       |  partially   |
| Weapon and companion swaping         |      ❌       |
| Sliders (morph targets/bone scaling) |      ✔️      |
| Custom companions                    |      ❌       |
| Provide a framework template         |      ✔️      |
| Allow custom placement of assets     |      ✔️      |
| Save system                          |      ✔️      |
| Async mod scanning                   |      ✔️      |
| Custom mod scan ranges               |      ✔️      |
| Custom integrated UI                 |      ✔️      |
| Custom hardware cursor               |      ✔️      |

## How it works

The framework works by attaching proxy meshes to the character and forcing them to copy the pose of the mesh which they are attached to and hide the original, creating the illusion of the game mesh being replaced.

This works because the framework replaces the default skin and makes it point to a proxy post process animation blueprint which serves as the entry point.
From there, the system spawns the different proxy meshes and initializes itself.

Because the framework spawns a new skeletal mesh, this mesh can have a **custom skeleton** as long as the base rig is kept intact for the animation copy to work properly.
This means that a custom skeleton can be imported into the Unreal project and packaged into the mod, and the outfit doesn't have to reference the base skeleton.
This allows mod authors to extend the base skeleton and add new bones and animate them with **kawaii physics** for example. This works perfectly for skirts, hair physics, accessory physics, and so on.

> [!WARNING]
> Make sure the custom skeleton "inherits" from the base game skeleton (you add bones "on top" of the base game skeleton)
> Otherwise the framework is unable to copy the animations from the game mesh

By pressing F5, the framework UI & editor can be opened.
When the UI is opened, mods are grouped by author (author ID) and individual outfits can be selected and edited.
A save system is implemented so that each outfit edits are applied everytime said skin is equipped.

The UI can be pulled at any point as long as the game character can receive inputs and the player controller has inputs enabled.
It will pause the game, but buttons are available to unpause the game if the user wants to.
This allows the UI to be spawned during most cinematics, allowing users to swap skins even during cinematics.

The framework makes extensive use of **soft references** to validate assets and for modularity reasons.
This allows for example, mod authors to create one outfit config, register 5 outfits, and then split those 5 outfits into 5 different pak files instead of 1 containing all outfits.
Because the meshes are referenced by a soft reference, if a given outfit is not present (for example only 3 pak files out of the 5 are installed in the game), the framework will simply skip the missing ones.
This helps with the process of creating config files by mod authors with lots of optional fields.

A custom hardware cursor is packed into `pakchunk69`, this chunk can be ignored if you do not wish to install the custom cursor.

#### General chunk assignment

| CHUNK | CONTENT                                        | MANDATORY? |
|:-----:|:-----------------------------------------------|:----------:|
|   9   | Contains the initializer proxy mesh            |     ✔️     |
|  69   | Contains the custom hardware cursors           |     ❌      |
| 1000  | Contains the framework logic                   |     ✔️     |
| 30000 | Contains the modular scan range for 4096 mods  |     ❌      |
| 30001 | Contains the modular scan range for 8192 mods  |     ❌      |
| 30002 | Contains the modular scan range for 16384 mods |     ❌      |
| 30003 | Contains the modular scan range for 32768 mods |     ❌      |
| 30004 | Contains the modular scan range for 65536 mods |     ❌      |
| 30005 | Contains the modular scan range for all mods   |     ❌      |
| Other | Contains test stuff                            |     ❌      |

Chunk 9 could be indeed merged with chunk 1000, however, for flexibility reasons, the 2 are separated.
This allows, for example, for an easy integration with UE4SS if you wish to do so.

# A major warning

If, you the developer, wish to modify, extend or write your own version of this framework, Please be aware of the fallowing:

> [!CAUTION]
> This framework (as is) relies on **Blueprint Structures**. Said structures are <span style="color:red">not to be modifed, renamed, or moved in any shape or form</span>. This includes member names, member descriptions, member types, member count, member metadata, etc... Blueprint sutructures are known to be quite the hassle when attempting to modify, rename or move them. Not only you risk to <span style="color:red">corrupt your project or generate countless amount of errors + crashes</span>, but you will also break all mods that use the framework.
>
> For this reason, it is **HIGHLY** recommended that the data of new features are stored on NEW structures rather than modifying the existing ones.
>
> This will also help with the compatibility of mods using this framework across different versions.

> [!TIP]
> It is highly recommended to use extensive and exclusive use of **soft references** when available.
> This increases the compatibility of mods across different framework versions and allows for modular asset loading.
> Using hard references may increase memory usage and can lead to errors and crashes at runtime if assets are missing or fail to load. 

