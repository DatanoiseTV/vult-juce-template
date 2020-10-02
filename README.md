# vult-juce-template
Starter template for Vult DSP using the JUCE framework.

It will run the "selfplay.vult" demo code by default.

## Running different DSP code

```
vultc -ccode -o vultgen file.vult
```

Move the resulting files vultgen.* to Source/vult/ and adjust data types accordingly in MainComponent.{h,cpp}
