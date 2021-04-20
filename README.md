# SPTC (Serial Pass-Through Controller)

## Setup Dependencies
1. CLion - Development IDE
1. STM32CubeMX - Microcontroller configuration
1. OpenOCD - CLion open source debugging tool for the microcontroller
1. GNU ARM Toolchain - Cross compile toolchain

## Setup Procedure
1. Setup CLion
1. Follow [this](https://www.jetbrains.com/help/clion/2021.1/embedded-development.html?utm_source=product&utm_medium=link&utm_campaign=CL&utm_content=2021.1) procedure to set up dependencies.
1. Use CLion for development and debugging

## Notes
1. Some modifications were made to the default CLion/STM32Cube configuration for organizational purposes.  Those changes are documented below:
    1. Typically there would be an "Inc", "Src" and "Startup" directory at the root level.  Those have been relocated to the "Core" directory.  If STM32CubeMX is used to generate new files, these directories will need to be moved and the CMakeLists.txt updated to reflect the location change.
    1. Files created for, and related, to this project are located under the "Project" directory.
    1. The CMakeLists_template.txt was updated as follows
        1. Uncommented the FPU related definitions
        1. Added the project directories to the include and file glob directives
        1. Added linker specs to allow the use of C++