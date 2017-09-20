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
private:
	bool masks;
	 unsigned long long offset_id;
	 int32 limit;
	MESSAGES::ArchivedStickers* result;
};
} //end namespace block
