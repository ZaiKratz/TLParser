#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class FoundGif : public TLBaseObject
{
public:
	FoundGif();
	FoundGif(FString url, FString thumb_url, FString content_url, FString content_type, int32 w, int32 h);

	~FoundGif();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	FString url;
	 FString thumb_url;
	 FString content_url;
	 FString content_type;
	 int32 w;
	 int32 h;
};
} //end namespace block
