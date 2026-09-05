# for Windows only
# use this powershell file to build or clean up your application
#
# It may happen, that your powershell script is unable to run on your
# system due security options. In that case try to type that command
# in the command line:
# Set-ExecutionPolicy -Scope Process -ExecutionPolicy Bypass
# to bypass that limitation unless you're logged out

# use the additional argument as "action" to determine,
# which argument was given

#   --------------
#   define, that $Action is a variable of type
#   string with an empty assigned string
#   => in use in switch block (end of file)
#   --------------
param (
    [string]$Action=""
)

#   --------------
#   variables
#   --------------

$compiler = "gcc.exe"

$flags = @(
    "-Wall"
)

$sources = @(
    "src/main.c"
    "src/math_functions.c"
)

$linker = @(
    "-Iheader"
    "-o"
)

$executable = "math_tester.exe"


#   --------------
#   functions
#   --------------

function help_function {
    $script_name = $MyInvocation.MyCommand.Name
    $summary = @"
    usage: .\$script_name [build | clean]
"@
    Write-Host $summary
}

function build_app {
   & $compiler $flags $sources $linker $executable
}

function clean_up {
    if (Test-Path $executable) {
        Remove-Item $executable
        Write-Host "$executable has been removed"
    } else {
        Write-Host "$executable does not exist; nothing to do here..."
    }
}

#   --------------
#   now determine which argument was given
#   --------------
switch ($Action.ToLower()) {
    "build" { build_app }
    "clean" { clean_up }
    default { help_function }
}