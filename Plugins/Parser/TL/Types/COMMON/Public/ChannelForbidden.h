#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/Chat.h"

//begin namespace block
namespace COMMON
{
class ChannelForbidden : public TLBaseObject
{
public:
	ChannelForbidden();
	ChannelForbidden(bool broadcast, bool megagroup, int32 id, unsigned long long access_hash, FString title, FDateTime until_date);

	~ChannelForbidden();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	bool broadcast;
	 bool megagroup;
	 int32 id;
	 unsigned long long access_hash;
	 FString title;
	 FDateTime until_date;
};
} //end namespace block
