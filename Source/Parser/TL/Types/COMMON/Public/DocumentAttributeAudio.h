#pragma once
#include "Engine.h"
#include "../../../Types/Private/DocumentAttribute.h"

#include "../../../Types/Private/DocumentAttribute.h"

//begin namespace block
namespace COMMON
{
class DocumentAttributeAudio : public PRIVATE::DocumentAttribute
{
public:
	DocumentAttributeAudio();
	DocumentAttributeAudio(bool voice, int32 duration, FString title, FString performer, TArray<uint8> waveform);

	~DocumentAttributeAudio();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	bool Getvoice() const
	{
		 return this->voice;
	}

	int32 Getduration() const
	{
		 return this->duration;
	}

	FString Gettitle() const
	{
		 return this->title;
	}

	FString Getperformer() const
	{
		 return this->performer;
	}

	TArray<uint8>  Getwaveform() const
	{
		 return this->waveform;
	}

private:
	bool voice;
	 int32 duration;
	 FString title;
	 FString performer;
	 TArray<uint8> waveform;
};
} //end namespace block
