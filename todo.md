**TO-DO**

*Lilly*

<!-- -> convert floor and ceiling color (rgb) to actual color -->
<!-- -> stop textures from moving with the player -->
<!-- -> check Error messages to start with "ERROR\n" and then having a description -->
<!-- -> check minimapsize always being the same size, no matter the mapsize -->
<!-- -> check screen size and set error if too big? -->
<!-- -> try to be able to use 2 keys at once -->
<!-- -> what if map is not a square? -->
<!-- -> add doors which can open and close -->
<!-- -> add more textures -->
<!-- -> rotate the view with the mouse -->
-> add animated sprites
<!-- -> fix textures being displayed mirrored -->
<!-- -> display textures for doors -->


*Monika*
-> check map if includes '2' or other characvters, also doesnt work with 'P'
-> take out TAB etc
-> check for only one player, also needs at least one
-> add check for ".cub" file being only ".cub", if yes: error. has to have at least some character before that (=like this: "x.cub")
-> empty lines inside the file can ONLY have a newline, no spaces etc.
-> invalid_space.cub doesnt display an error

1. Map Format and Structure

    Empty map file: The map file is completely empty.
    Unenclosed map: The map is not surrounded by walls (1), allowing leaks.
    Invalid characters or symbols inside map: Such as letters other than the defined ones (N, S, E, W, 1, 0, ).
    Multiple player start positions: More than one N, S, E, or W defined.
    No player start position: No N, S, E, or W defined in the map.
    Spaces within the map grid: Gaps in the walls where spaces exist between other map characters.
    Holes due to spaces: Spaces adjacent to walkable areas (0) without being enclosed.
    Disconnected map sections: Parts of the map are not reachable due to being isolated.
    Diagonal openings: Openings formed at corners that allow leaks.

2. File Format and Inputs

    Missing .cub extension: The file doesn't end with .cub.
    Nonexistent file: The file path does not point to a real file.
    Invalid .cub file: The file contains unrelated or junk content.
    Permissions issues: The file exists but cannot be read (e.g., wrong permissions).

3. Textures and Colors

    Missing texture paths: One or more texture paths (NO, SO, WE, EA) are missing.
    Duplicate texture definitions: A texture (e.g., NO) is defined multiple times.
    Invalid texture file path: The path points to a nonexistent file or invalid file type.
    Corrupted texture file: The file exists but is not a valid .xpm or usable format.
    Missing RGB color definitions: One or both of F (floor) or C (ceiling) colors are missing.
    Invalid RGB values: RGB values are out of range (0–255) or contain extra data.
    Duplicate color definitions: F or C is defined multiple times.
    Extra commas or missing commas in RGB: Improperly formatted color values.
    Whitespace issues: Leading, trailing, or excessive whitespace in texture or color definitions. (spaces are allowed)

4. Configuration File Parsing

    Incorrect order of elements: map is not the last part
    Unknown identifiers: Unexpected identifiers not defined in the specification.
    Comments: Misinterpreting lines that may appear to be comments but are invalid in .cub.
    Empty or invalid map section: The map comes after other parameters but is malformed.
    Extra parameters: Additional invalid entries or sections beyond what is required.

5. Memory and Performance

    Memory leaks: Improper allocation or freeing of memory during parsing.
    Large files: Extremely large .cub files or maps that push memory limits.
    Infinite loops in parsing: Issues with improperly terminated loops (e.g., reading lines).

6. Norm and Coding Style Restrictions

    Line length: Lines exceeding the allowed 80 or 25-line function limit.
    Global variables: Avoiding unintended global variable use in parsing logic.
    Error handling: Failing to free memory and close file descriptors upon errors.

7. Error Handling

    Ambiguous error messages: Providing vague or misleading error descriptions.
    Crashes on invalid input: Ensure robust handling of all edge cases without segmentation faults or undefined behavior.
    Exiting on success without a proper map: Parsing succeeds despite an invalid .cub.

8. Special Input Cases

    Whitespace-only lines: Lines with only spaces or tabs. (are invalid!)
    Non-printable characters: Hidden or control characters in the file.
    Texture file format: Using textures in unsupported formats (e.g., .png instead of .xpm).
    Color overflow: Values like 255,255,256 or negative RGB values.

Example Test Cases

To ensure your parser is robust, test these scenarios:

    A valid .cub file (baseline test).
    A map with diagonal holes (e.g., 1 0 1).
    Spaces outside or inside the map grid.
    Missing NO, SO, WE, or EA.
    F 255,255, or C 0,,255.
    A disconnected map section.
                
 % ./cub3d_bonus .test.cub

 % ./cub3d_bonus ./.cub

 bonus: doors open to the right

 sprint button
