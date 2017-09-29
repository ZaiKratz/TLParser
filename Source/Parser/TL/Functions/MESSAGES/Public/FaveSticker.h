#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputDocument.h"

//begin namespace block
namespace MESSAGES
{
class FaveSticker : public TLBaseObject
{
public:
	FaveSticker();
	FaveSticker(COMMON::InputDocument* id, bool unfave);

	~FaveSticker();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	COMMON::InputDocument*  Getid() const
	{
		 return this->id;
	}

	bool Getunfave() const
	{
		 return this->unfave;
	}

	bool GetResult() const
	{
		 return this->result;
	}

private:
	COMMON::InputDocument* id;
	 bool unfave;
	bool result;
};
} //end namespace block
