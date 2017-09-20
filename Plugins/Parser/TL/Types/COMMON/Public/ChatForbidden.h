#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/Chat.h"

//begin namespace block
namespace COMMON
{
class ChatForbidden : public TLBaseObject
{
public:
	ChatForbidden();
	ChatForbidden(int32 id, FString title);

	~ChatForbidden();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 id;
	 FString title;
};
} //end namespace block
