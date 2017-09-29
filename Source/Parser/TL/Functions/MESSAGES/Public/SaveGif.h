#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputDocument.h"

//begin namespace block
namespace MESSAGES
{
class SaveGif : public TLBaseObject
{
public:
	SaveGif();
	SaveGif(COMMON::InputDocument* id, bool unsave);

	~SaveGif();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	COMMON::InputDocument*  Getid() const
	{
		 return this->id;
	}

	bool Getunsave() const
	{
		 return this->unsave;
	}

	bool GetResult() const
	{
		 return this->result;
	}

private:
	COMMON::InputDocument* id;
	 bool unsave;
	bool result;
};
} //end namespace block
