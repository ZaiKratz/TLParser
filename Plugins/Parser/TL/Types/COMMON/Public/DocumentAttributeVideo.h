#pragma once
#include "Engine.h"
#include "../../../Types/Private/DocumentAttribute.h"

#include "../../../Types/Private/DocumentAttribute.h"

//begin namespace block
namespace COMMON
{
class DocumentAttributeVideo : public PRIVATE::DocumentAttribute
{
public:
	DocumentAttributeVideo();
	DocumentAttributeVideo(bool round_message, int32 duration, int32 w, int32 h);

	~DocumentAttributeVideo();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	bool round_message;
	 int32 duration;
	 int32 w;
	 int32 h;
};
} //end namespace block