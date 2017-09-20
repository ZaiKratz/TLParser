#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Messages/Public/RecentStickers.h"

//begin namespace block
namespace MESSAGES
{
class GetRecentStickers : public TLBaseObject
{
public:
	GetRecentStickers();
	GetRecentStickers(bool attached, int32 hash);

	~GetRecentStickers();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	bool attached;
	 int32 hash;
	MESSAGES::RecentStickers* result;
};
} //end namespace block
