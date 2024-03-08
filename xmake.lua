set_xmakever("2.8.7")

set_allowedmodes("releasedbg", "release", "debug")
add_rules("mode.debug")

set_project("moebius")
MOEBIUS_VERSION= "1.4.0"

local moe_files = {
    "Data/Drd/**.cpp",
    "Data/Scheme/**.cpp",
    "Data/Tree/**.cpp",
    "Kernel/Types/**.cpp",
}
local moe_includedirs = {
    "Data/Drd",
    "Data/Scheme",
    "Data/Tree",
    "Kernel/Types",
}

add_repositories("moe-repo xmake")

local LOLLY_VERSION= "1.4.1"
local DOCTEST_VERSION = "2.4.11"

add_requires("lolly " .. LOLLY_VERSION)
add_requires("doctest " .. DOCTEST_VERSION, {system=false})


target("libmoebius") do
    set_kind ("static")
    set_languages("c++17")
    set_encodings("utf-8")
    set_basename("moebius")

    add_includedirs(moe_includedirs)
    add_files(moe_files)

    add_packages("lolly")
end

target("tests") do
    set_kind ("binary")
    set_default (false)

    add_deps("libmoebius")

    add_includedirs(moe_includedirs)
    add_includedirs("tests")

    add_packages("lolly")

    cpp_tests_on_all_plat = os.files("tests/**_test.cpp")
    for _, testfile in ipairs(cpp_tests_on_all_plat) do
        add_tests(path.basename(testfile), {
            kind = "binary",
            files = testfile,
            languages = "c++17",
            packages = "doctest",
            defines = "DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN"})
    end
end
