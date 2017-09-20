#pragma once
#include "Engine.h"
#include "../../../Types/Private/InputStickeredMedia.h"

#include "../../../Types/Common/Public/InputPhoto.h"
#include "../../../Types/Private/InputStickeredMedia.h"

//begin namespace block
namespace COMMON
{
class InputStickeredMediaPhoto : public PRIVATE::InputStickeredMedia
{
public:
	InputStickeredMediaPhoto();
	InputStickeredMediaPhoto(COMMON::InputPhoto* id);

	~InputStickeredMediaPhoto();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	COMMON::InputPhoto* id;
};
} //end namespace block
