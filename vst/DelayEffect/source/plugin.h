#ifndef __plugin__
#define __plugin__
#include "pluginadapter.h"
#include "DelayProcessor.h"

namespace Steinberg {
namespace Vst {

// change these numbers!
// every plugin needs a unique UID
static const FUID PluginUID (0x84E8AE6F, 0x92554F53, 0x96FAE413, 0x3C935A18);

// define parameter tags here:
enum {
	kDelayId = 0, 
	kAmountId,
	kFeedbackId
};


class Plugin : public PluginAdapter
{
public:
	Plugin();
	virtual ~Plugin(){}
	tresult PLUGIN_API initialize(FUnknown* context);
	tresult PLUGIN_API process(ProcessData& data);
	void startProcessing(int numChannels, SampleRate sampleRate);
	static FUnknown* createInstance(void*) { return (IAudioProcessor*)new Plugin(); }
private:
	int numChannels;
	SampleRate sampleRate;
private:
	DelayProcessor leftProcessor;
	DelayProcessor rightProcessor;
};


}} // namespaces

#endif //__plugin__
