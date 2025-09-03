# UmbraFramework for Stellar Blade

This framework is a personal modding project. UmbraFramework aims to provide a way to allow users to install endless amount of skins to their games while only replacing the default suit as well as provide an easy way for modders to create and integrate their outfits to the Framework.
An Unreal project template is provided with various outfit setup examples.
The framework also provides an easy way to configure outfit customization for users to play around with. This includes color edits, visibility edits (hidding material sections), sliders (morphs/bone scaling), and material scalar parameters. This editing system can be used on any part of the framework; This includes, but is not limited to: base body, head, hair, accessory, etc...
Providing a wide range of customization to the user.

The framework template includes some Unreal Editor tutorials that will explain some of the basics on how to setup your mods using this framework.

This framework is made public to serve as knowledge base and a base for other users to extend and improve upon this framework.

> [!INFO]
> By using this framework, it is assumed that you have minimal knowledge on: Unreal Engine, C++, Blueprints, modding with Unreal Engine, Programming in general, Blueprint data types and communication

> [!NOTE]
> This framework is not perfect nor complete. Some bugs still exist within the codebase and the code isn't the cleanest code you'll ever see.

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
- the project contains a working version of `kawaii physics` (working in game and preview in editor)

## Features

| FEATURE                                   | IMPLEMENTED? |
|-------------------------------------------|--------------|
| Support large <br/> amounts of skins      | ✔️           |
| Custom rigs                               | ✔️           |
| Custom materials                          | ✔️           |
| Outfit customization                      | ✔️           |
| head/hair/accessories swapping            | partially    |
| Sliders <br/>(morph targets/bone scaline) | ✔️           |
| Custom companions                         | ❌            |
| Provide a framework template              | ✔️           |
| Allow custom placement <br/>of assets     | ✔️           |
| Save system                               | ✔️           |
| Async mod scanning                        | ✔️           |
| Custom mod scan ranges                    | ✔️           |

## A major warning
If, you the developer, wish to modify, extend or write your own version of this framework, Please be aware of the fallowing:

> [!WARNING]
> This framework (as is) relies on **Blueprint Structures**. Said structures are <span style="color:red">not to be modifed, renamed, or moved in any shape or form</span>. This includes member names, member descriptions, member types, member count, member metadata, etc... Blueprint sutructures are known to be quite the hassle when attempting to modify it. Not only you risk to <span style="color:red">corrupt your project or generate countless amount of errors + crashes</span>, but you will also break all mods that use the framework.
> For this reason, it is **HIGHLY** recommended that new features data are stored on NEW structures rather than modifying the existing ones.