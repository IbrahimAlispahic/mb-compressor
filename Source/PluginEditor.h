/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
struct Placeholder : juce::Component {
    
    Placeholder();
    
    void paint(juce::Graphics& g) override {
        g.fillAll(customColour);
    }
    
    juce::Colour customColour;
};
/**
*/
class MBCompAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    MBCompAudioProcessorEditor (MBCompAudioProcessor&);
    ~MBCompAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    MBCompAudioProcessor& audioProcessor;
    
    /*
     Editor will be split into 4 sections:
     1. Control bar at the top - analyzer power button and global btypass button
     2. Spectrum analyzer with part that shows thresholds and gain reduction
     3. Global controls
     4. Actual compressor band controls
     */
    
    Placeholder controlBar, analyzer, globalControls, bandControls;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MBCompAudioProcessorEditor)
};
