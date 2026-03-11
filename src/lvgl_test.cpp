#include "lvgl_test.h"

static void anim_x_cb(void * var, int32_t v)
{
    lv_obj_set_x((lv_obj_t *)var, v);
}

static void anim_y_cb(void * var, int32_t v)
{
    lv_obj_set_y((lv_obj_t *)var, v);
}

void ui_test_perf(void)
{
    lv_obj_t * scr = lv_scr_act();
    lv_obj_clean(scr);

    lv_obj_set_style_bg_color(scr, lv_color_hex(0x101010), 0);

    lv_obj_t * title = lv_label_create(scr);
    lv_label_set_text(title, "LVGL Perf Test");
    lv_obj_align(title, LV_ALIGN_TOP_MID, 0, 8);

    /* 创建一些持续运动的方块，数量越多压力越大 */
    for(int i = 0; i < 12; i++) {
        lv_obj_t * obj = lv_obj_create(scr);
        lv_obj_set_size(obj, 32, 32);
        lv_obj_set_style_radius(obj, 6, 0);
        lv_obj_set_style_border_width(obj, 0, 0);
        lv_obj_set_style_bg_opa(obj, LV_OPA_COVER, 0);
        lv_obj_set_style_bg_color(obj, lv_palette_main((lv_palette_t)((i % 6) + 1)), 0);

        lv_obj_set_pos(obj, 10 + (i % 4) * 70, 40 + (i / 4) * 55);

        lv_anim_t ax;
        lv_anim_init(&ax);
        lv_anim_set_var(&ax, obj);
        lv_anim_set_exec_cb(&ax, anim_x_cb);
        lv_anim_set_values(&ax, 0, 280);
        lv_anim_set_time(&ax, 1000 + i * 80);
        lv_anim_set_playback_time(&ax, 1000 + i * 80);
        lv_anim_set_repeat_count(&ax, LV_ANIM_REPEAT_INFINITE);
        lv_anim_start(&ax);

        lv_anim_t ay;
        lv_anim_init(&ay);
        lv_anim_set_var(&ay, obj);
        lv_anim_set_exec_cb(&ay, anim_y_cb);
        lv_anim_set_values(&ay, 35 + (i / 4) * 50, 170 - (i / 4) * 15);
        lv_anim_set_time(&ay, 800 + i * 60);
        lv_anim_set_playback_time(&ay, 800 + i * 60);
        lv_anim_set_repeat_count(&ay, LV_ANIM_REPEAT_INFINITE);
        lv_anim_start(&ay);
    }
}