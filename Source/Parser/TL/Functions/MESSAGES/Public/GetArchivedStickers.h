#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Messages/Public/ArchivedStickers.h"

//begin namespace block
namespace MESSAGES
{
class GetArchivedStickers : public TLBaseObject
{
public:
	GetArchivedStickers();
	GetArchivedStickers(bool masks, unsigned long long offset_id, int32 limit);

	~GetArchivedStickers();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	bool Getmasks() const
	{
		 return this->masks;
	}

	unsigned long long GetOffsetId() const
	{
		 return this->offset_id;
	}

	int32 Getlimit() const
	{
		 return this->limit;
	}

	MESSAGES::ArchivedStickers* GetResult() const
	{
		 return this->result;
	}

private:
	bool masks;
	 unsigned long long offset_id;
	 int32 limit;
	MESSAGES::ArchivedStickers* result;
};
} //end namespace block
