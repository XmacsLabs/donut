set_xmakever("2.8.7")

set_allowedmodes("releasedbg", "release", "debug")
add_rules("mode.debug")

set_project("moebius")
MOEBIUS_VERSION= "1.4.0"

local moe_files = {
    "Data/Drd/**.cpp",
    "Data/Tree/**.cpp",
}
local moe_includedirs = {
    "Data/Drd",
    "Data/Tree",
}

add_repositories("moe-repo xmake")

LOLLY_VERSION= "1.4.0"
add_requires("lolly " .. LOLLY_VERSION)

target("libmoebius") do
    set_kind ("static")
    set_languages("c++17")
    set_encodings("utf-8")
    set_basename("moebius")

    add_includedirs(moe_includedirs)
    add_files(moe_files)

    add_packages("lolly")
end
