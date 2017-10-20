#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputPhoto.h"

//begin namespace block
namespace COMMON
{
class InputStickeredMediaPhoto : public TLBaseObject
{
public:
	InputStickeredMediaPhoto();
	InputStickeredMediaPhoto(COMMON::InputPhoto* id);

	~InputStickeredMediaPhoto();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	COMMON::InputPhoto*  Getid() const
	{
		 return this->id;
	}

private:
	COMMON::InputPhoto* id;
};
} //end namespace block
