#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/Chat.h"

//begin namespace block
namespace COMMON
{
class ChatEmpty : public TLBaseObject
{
public:
	ChatEmpty();
	ChatEmpty(int32 id);

	~ChatEmpty();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 id;
};
} //end namespace block
