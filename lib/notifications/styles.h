
LV_FONT_DECLARE(Oswald);
LV_FONT_DECLARE(Mostane_20);

static const lv_style_const_prop_t listMain_props[] = {
    LV_STYLE_CONST_PAD_LEFT(0),
    LV_STYLE_CONST_PAD_RIGHT(0),
    LV_STYLE_CONST_PAD_TOP(0),
    LV_STYLE_CONST_PAD_BOTTOM(0),
    LV_STYLE_CONST_PAD_ROW(0),
    LV_STYLE_CONST_BORDER_WIDTH(0),
    LV_STYLE_CONST_PROPS_END
};
static const LV_STYLE_CONST_INIT(listMain, listMain_props);

static const lv_style_const_prop_t listScrollbar_props[] = {
    LV_STYLE_CONST_WIDTH(2),
    LV_STYLE_CONST_PROPS_END
};
static const LV_STYLE_CONST_INIT(listScrollbar, listScrollbar_props);

static const lv_style_const_prop_t tight_props[] = {
    LV_STYLE_CONST_PAD_LEFT(0),
    LV_STYLE_CONST_PAD_RIGHT(0),
    LV_STYLE_CONST_PAD_TOP(0),
    LV_STYLE_CONST_PAD_BOTTOM(0),
    LV_STYLE_CONST_PAD_ROW(0),
    LV_STYLE_CONST_PAD_COLUMN(0),
    LV_STYLE_CONST_RADIUS(0),
    LV_STYLE_CONST_BORDER_WIDTH(0),
    LV_STYLE_CONST_OUTLINE_WIDTH(0),
    LV_STYLE_CONST_BORDER_SIDE(LV_BORDER_SIDE_NONE),
    LV_STYLE_CONST_BG_COLOR(LV_COLOR_MAKE(0xFF, 0xFF, 0xFF)), // White
    LV_STYLE_CONST_TEXT_COLOR(LV_COLOR_MAKE(0x00, 0x00, 0x00)), // Black
    LV_STYLE_CONST_BG_OPA(LV_OPA_COVER),
    LV_STYLE_CONST_TEXT_FONT(&Oswald),
    LV_STYLE_CONST_PROPS_END
};
static const LV_STYLE_CONST_INIT(tight, tight_props);

static const lv_style_const_prop_t tightTitle_props[] = {
    LV_STYLE_CONST_TEXT_FONT(&Mostane_20),
    LV_STYLE_CONST_PROPS_END
};
static const LV_STYLE_CONST_INIT(tightTitle, tightTitle_props);

static const lv_style_const_prop_t tight_aoCard_props[] = {
    LV_STYLE_CONST_BORDER_WIDTH(1),
    LV_STYLE_CONST_BORDER_SIDE(LV_BORDER_SIDE_BOTTOM),
    LV_STYLE_CONST_MAX_HEIGHT(64),
    LV_STYLE_CONST_PROPS_END
};
static const LV_STYLE_CONST_INIT(tight_aoCard, tight_aoCard_props);

static const lv_style_const_prop_t tight_aoHeader_props[] = {
    LV_STYLE_CONST_PAD_COLUMN(2),
    LV_STYLE_CONST_PROPS_END
};
static const LV_STYLE_CONST_INIT(tight_aoHeader, tight_aoHeader_props);

static const lv_style_const_prop_t tight_aoTitle_props[] = {
    LV_STYLE_CONST_MAX_WIDTH(72),
    LV_STYLE_CONST_TEXT_FONT(&Oswald),
    LV_STYLE_CONST_PROPS_END
};
static const LV_STYLE_CONST_INIT(tight_aoTitle, tight_aoTitle_props);

static const lv_style_const_prop_t tight_aoMsgLabel_props[] = {
    LV_STYLE_CONST_MAX_HEIGHT(50),
    {0}
};
static const LV_STYLE_CONST_INIT(tight_aoMsgLabel, tight_aoMsgLabel_props);