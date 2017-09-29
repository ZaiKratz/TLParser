#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputDocument.h"

//begin namespace block
namespace MESSAGES
{
class SaveRecentSticker : public TLBaseObject
{
public:
	SaveRecentSticker();
	SaveRecentSticker(bool attached, COMMON::InputDocument* id, bool unsave);

	~SaveRecentSticker();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	bool Getattached() const
	{
		 return this->attached;
	}

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
	bool attached;
	 COMMON::InputDocument* id;
	 bool unsave;
	bool result;
};
} //end namespace block
