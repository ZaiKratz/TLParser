#pragma once
#include "Engine.h"
#include "../../../Types/Private/MessageMedia.h"

#include "../../../Types/Private/InputPeer.h"
#include "../../../Types/Private/InputMedia.h"
#include "../../../Types/Private/MessageMedia.h"

//begin namespace block
namespace MESSAGES
{
class UploadMedia : public PRIVATE::MessageMedia
{
public:
	UploadMedia();
	UploadMedia(PRIVATE::InputPeer* peer, PRIVATE::InputMedia* media);

	~UploadMedia();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	PRIVATE::InputPeer*  Getpeer() const
	{
		 return this->peer;
	}

	PRIVATE::InputMedia*  Getmedia() const
	{
		 return this->media;
	}

	PRIVATE::MessageMedia* GetResult() const
	{
		 return this->result;
	}

private:
	PRIVATE::InputPeer* peer;
	 PRIVATE::InputMedia* media;
	PRIVATE::MessageMedia* result;
};
} //end namespace block
