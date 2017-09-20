#pragma once
#include "Engine.h"
#include "../../../Types/Private/InputStickeredMedia.h"

#include "../../../Types/Common/Public/InputDocument.h"
#include "../../../Types/Private/InputStickeredMedia.h"

//begin namespace block
namespace COMMON
{
class InputStickeredMediaDocument : public PRIVATE::InputStickeredMedia
{
public:
	InputStickeredMediaDocument();
	InputStickeredMediaDocument(COMMON::InputDocument* id);

	~InputStickeredMediaDocument();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	COMMON::InputDocument* id;
};
} //end namespace block
