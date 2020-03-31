/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
HardClipAudioProcessor::HardClipAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
   
}

HardClipAudioProcessor::~HardClipAudioProcessor()
{
}

//==============================================================================
const String HardClipAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool HardClipAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool HardClipAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool HardClipAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double HardClipAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int HardClipAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int HardClipAudioProcessor::getCurrentProgram()
{
    return 0;
}

void HardClipAudioProcessor::setCurrentProgram (int index)
{
}

const String HardClipAudioProcessor::getProgramName (int index)
{
    return {};
}

void HardClipAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void HardClipAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    sampleCountDown = 0;
}

void HardClipAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool HardClipAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) /*override*/
{
    
}

void HardClipAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    auto mainInputOutput = getBusBuffer (buffer, true, 0);

   
    for (auto j = 0; j < buffer.getNumSamples(); ++j)
    {
        // very in-effective way of doing this
        for (auto i = 0; i < mainInputOutput.getNumChannels(); ++i)
        {
            auto readPointer = *mainInputOutput.getReadPointer (i, j);
            readPointer = readPointer * 100000; //drive
            readPointer = readPointer > 0.2f ? 0.2f : readPointer; //clip reduction
            readPointer = readPointer < -0.2f ? -0.2f : readPointer; //clip reduction
//            if(readPointer != 0)
//                std::cout << readPointer << std::endl;
            *mainInputOutput.getWritePointer (i, j) =  readPointer;
        }
                                                                    
    }
}

//==============================================================================
bool HardClipAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* HardClipAudioProcessor::createEditor()
{
    return new HardClipAudioProcessorEditor (*this);
}

//==============================================================================
void HardClipAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void HardClipAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new HardClipAudioProcessor();
}
