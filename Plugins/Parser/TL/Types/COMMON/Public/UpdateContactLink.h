#pragma once
#include "Engine.h"
#include "../../../Types/Private/Update.h"

#include "../../../Types/Private/ContactLink.h"
#include "../../../Types/Private/Update.h"

//begin namespace block
namespace COMMON
{
class UpdateContactLink : public PRIVATE::Update
{
public:
	UpdateContactLink();
	UpdateContactLink(int32 user_id, PRIVATE::ContactLink* my_link, PRIVATE::ContactLink* foreign_link);

	~UpdateContactLink();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 user_id;
	 PRIVATE::ContactLink* my_link;
	 PRIVATE::ContactLink* foreign_link;
};
} //end namespace block
