#pragma once
#include "Engine.h"
#include "../../../Types/Private/Update.h"

#include "../../../Types/Common/Public/WebPage.h"
#include "../../../Types/Private/Update.h"

//begin namespace block
namespace COMMON
{
class UpdateWebPage : public PRIVATE::Update
{
public:
	UpdateWebPage();
	UpdateWebPage(COMMON::WebPage* webpage, int32 pts, int32 pts_count);

	~UpdateWebPage();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	COMMON::WebPage* webpage;
	 int32 pts;
	 int32 pts_count;
};
} //end namespace block