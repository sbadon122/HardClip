/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
HardClipAudioProcessorEditor::HardClipAudioProcessorEditor (HardClipAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    
    setSize (400, 300);

}

HardClipAudioProcessorEditor::~HardClipAudioProcessorEditor()
{
}

//==============================================================================
void HardClipAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setColour (Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), Justification::centred, 1);
}

void HardClipAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
