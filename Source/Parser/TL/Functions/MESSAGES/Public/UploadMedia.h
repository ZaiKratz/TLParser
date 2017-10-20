#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace MESSAGES
{
class UploadMedia : public TLBaseObject
{
public:
	UploadMedia();
	UploadMedia(TLBaseObject* peer, TLBaseObject* media);

	~UploadMedia();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TLBaseObject*  Getpeer() const
	{
		 return this->peer;
	}

	TLBaseObject*  Getmedia() const
	{
		 return this->media;
	}

	TLBaseObject* GetResult() const
	{
		 return this->result;
	}

private:
	TLBaseObject* peer;
	 TLBaseObject* media;
	TLBaseObject* result;
};
} //end namespace block
