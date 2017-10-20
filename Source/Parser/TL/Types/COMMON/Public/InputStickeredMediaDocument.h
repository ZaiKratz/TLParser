#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputDocument.h"

//begin namespace block
namespace COMMON
{
class InputStickeredMediaDocument : public TLBaseObject
{
public:
	InputStickeredMediaDocument();
	InputStickeredMediaDocument(COMMON::InputDocument* id);

	~InputStickeredMediaDocument();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	COMMON::InputDocument*  Getid() const
	{
		 return this->id;
	}

private:
	COMMON::InputDocument* id;
};
} //end namespace block
