mkdir C:\Dev\QtWasm\build

docker run --rm -v C:\Dev\QtWasm\source:/project/source -v C:\Dev\QtWasm\build:/project/build forderud/wasmbuilder:qmake

pause