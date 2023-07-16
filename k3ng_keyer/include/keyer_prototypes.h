// function prototypes, in hopes of taming this beast.
void service_sending_pins(void);
void initialize_cw_keyboard(void);
void check_for_dirty_configuration();
void check_paddles();
void ptt_key();
void ptt_unkey();
void check_ptt_tail();
void write_settings_to_eeprom(int initialize_eeprom);
void service_async_eeprom_write();
int read_settings_from_eeprom();
void check_dit_paddle();
void check_dah_paddle();
void send_dit();
void send_dah();
void tx_and_sidetone_key (int state);
void loop_element_lengths(float lengths, float additional_time_ms, int speed_wpm_in);
void speed_change(int change);
void speed_change_command_mode(int change);
void speed_set(int wpm_set);
void command_speed_set(int wpm_set);
long get_cw_input_from_user(unsigned int exit_time_milliseconds);
void command_display_memory(byte memory_number);
void adjust_dah_to_dit_ratio(int adjustment);
void sidetone_adj(int hz);
void switch_to_tx_silent(byte tx);
void switch_to_tx(byte tx);
void initialize_analog_button_array();
void service_dit_dah_buffers();
void beep();
void boop();
void beep_boop();
void boop_beep();
void send_the_dits_and_dahs(char const * cw_to_send);
void send_char(byte cw_char, byte omit_letterspace);
int uppercase (int charbytein);
void clear_send_buffer();
void remove_from_send_buffer();
void add_to_send_buffer(byte incoming_serial_byte);
void service_send_buffer(byte no_print);
byte service_tx_inhibit_and_pause(void);
void initialize_pins(void);
void initialize_debug_startup();
void initialize_keyer_state();
void initialize_potentiometer();
void initialize_rotary_encoder();
void initialize_default_modes();
void initialize_watchdog();
void check_eeprom_for_initialization();
void initialize_eeprom(void);
void check_for_beacon_mode();
void check_for_debug_modes();
void initialize_serial_ports();
void initialize_ps2_keyboard();
void initialize_display();
void initialize_usb();
int paddle_pin_read(int pin_to_read);
void initialize_ethernet_variables();
void initialize_ethernet();
void initialize_udp();
void initialize_web_server();
void service_millis_rollover();
void initialize_sd_card();
byte is_visible_character(byte char_in);
void debug_blink();
void remove_from_send_buffer();
int convert_cw_number_to_ascii (long number_in);
void check_button0();
#if defined(FEATURE_BEACON_SETTING)
  void service_beacon();
#endif
#if defined(FEATURE_COMPETITION_COMPRESSION_DETECTION)
  void service_competition_compression_detection();
#endif
#if defined(FEATURE_4x4_KEYPAD) || defined(FEATURE_3x4_KEYPAD)
void service_keypad();
#endif
#ifdef FEATURE_STRAIGHT_KEY
  long service_straight_key();
#endif
#ifdef FEATURE_SLEEP   // Code contributed by Graeme, ZL2APV  2016-01-18
void check_sleep();
#endif
#ifdef FEATURE_LCD_BACKLIGHT_AUTO_DIM
void check_backlight();
#endif
#ifdef FEATURE_DISPLAY
void service_display();
void display_scroll_print_char(char charin);
void lcd_clear();
void lcd_center_print_timed(String lcd_print_string, byte row_number, unsigned int duration);
void clear_display_row(byte row_number);
void lcd_center_print_timed_wpm();
void send_tx();
#endif
#ifdef FEATURE_MEMORIES
void check_memory_repeat();
void put_memory_button_in_buffer(byte memory_number_to_put_in_buffer);
int memory_start(byte memory_number);
int memory_end(byte memory_number);
void command_set_mem_repeat_delay();
void initialize_eeprom_memories();
byte memory_nonblocking_delay(unsigned long delaytime);
byte play_memory(byte memory_number);
void program_memory(int memory_number);
#endif
#ifdef FEATURE_DEAD_OP_WATCHDOG
void check_for_dead_op();
#endif
#if (defined(FEATURE_PS2_KEYBOARD) || defined(FEATURE_USB_KEYBOARD)) && defined(FEATURE_MEMORIES)
void repeat_memory_msg(byte memory_number);
void ps2_usb_keyboard_play_memory(byte memory_number);
#endif
#ifdef FEATURE_PS2_KEYBOARD
void check_ps2_keyboard();
int ps2_keyboard_get_number_input(byte places,int lower_limit, int upper_limit);
#endif
#if defined(FEATURE_PS2_KEYBOARD) && defined(FEATURE_MEMORIES)
void ps2_keyboard_program_memory(byte memory_number);
#endif
#if (defined(FEATURE_PS2_KEYBOARD) || defined(FEATURE_USB_KEYBOARD)) && !defined(OPTION_SAVE_MEMORY_NANOKEYER)
void put_serial_number_in_send_buffer();
#endif
#ifdef DEBUG_CAPTURE_COM_PORT
void debug_capture ();
void debug_capture_dump();
#endif
#ifdef FEATURE_ROTARY_ENCODER
int chk_rotary_encoder();
#endif
#ifdef FEATURE_SIDETONE_SWITCH
void check_sidetone_switch();
#endif
#ifdef FEATURE_POTENTIOMETER
void check_potentiometer();
byte pot_value_wpm();
#endif
#ifdef FEATURE_HELL
void hell_test ();
void transmit_hell_char (byte hellchar);
void transmit_hell_pixels (const char* hell_pixels, byte hellchar);
void transmit_hell_pixel (byte hellbit);
#endif
#ifdef FEATURE_SEQUENCER
void check_sequencer_tail_time();
#endif
#ifdef FEATURE_COMMAND_MODE
void command_mode();
void command_set_serial_number();
void command_keying_compensation_adjust();
void command_dah_to_dit_ratio_adjust();
void command_weighting_adjust();
void command_tuning_mode();
void command_speed_mode(byte mode);
#endif
#if defined(FEATURE_COMMAND_MODE_PROGRESSIVE_5_CHAR_ECHO_PRACTICE) && defined(FEATURE_COMMAND_MODE)
void command_progressive_5_char_echo_practice();
#endif
#if defined(FEATURE_COMMAND_MODE) && !defined(OPTION_SIDETONE_DIGITAL_OUTPUT_NO_SQUARE_WAVE)
void command_sidetone_freq_adj();
#endif
#if defined(FEATURE_MEMORIES) && defined(FEATURE_BUTTONS)
void check_the_memory_buttons();
#endif
#if defined(FEATURE_MEMORIES) && defined(FEATURE_COMMAND_MODE)
void command_program_memory();
#endif
#ifdef FEATURE_BUTTONS
byte analogbuttonread(byte button_number);
void check_buttons();
#endif
#ifdef FEATURE_WINKEY_EMULATION
void winkey_unbuffered_speed_command(byte incoming_serial_byte);
void winkey_farnsworth_command(byte incoming_serial_byte);
void winkey_keying_compensation_command(byte incoming_serial_byte);
void winkey_first_extension_command(byte incoming_serial_byte);
void winkey_dah_to_dit_ratio_command(byte incoming_serial_byte);
void winkey_weighting_command(byte incoming_serial_byte);
void winkey_ptt_times_parm1_command(byte incoming_serial_byte);
void winkey_ptt_times_parm2_command(byte incoming_serial_byte);
void winkey_set_pot_parm1_command(byte incoming_serial_byte);
void winkey_set_pot_parm2_command(byte incoming_serial_byte);
void winkey_set_pot_parm3_command (byte incoming_serial_byte);
void winkey_setmode_command(byte incoming_serial_byte);
void winkey_sidetone_freq_command(byte incoming_serial_byte);
void winkey_set_pinconfig_command(byte incoming_serial_byte);
void winkey_load_settings_command(byte winkey_status,byte incoming_serial_byte);
void winkey_admin_get_values_command();
void winkey_port_write(byte byte_to_send,byte override_filter);
void service_winkey(byte action);
#endif
#ifdef FEATURE_COMMAND_LINE_INTERFACE
void service_command_line_interface(PRIMARY_SERIAL_CLS * port_to_use);
#endif
#if defined(FEATURE_SERIAL)
void check_serial();
#endif
#if defined(FEATURE_SERIAL_HELP) && defined(FEATURE_SERIAL) && defined(FEATURE_COMMAND_LINE_INTERFACE)
void serial_page_pause(PRIMARY_SERIAL_CLS * port_to_use,byte seconds_timeout);
void print_serial_help(PRIMARY_SERIAL_CLS * port_to_use,byte paged_help);
#endif
#if defined(FEATURE_SERIAL) && defined(FEATURE_WINKEY_EMULATION) && defined(OPTION_WINKEY_2_SUPPORT)
void winkey_eeprom_download();
#endif
#if defined(FEATURE_MEMORIES) || defined(FEATURE_COMMAND_LINE_INTERFACE)
void display_serial_number_character(char snumchar);
void serial_status_memories(PRIMARY_SERIAL_CLS * port_to_use);
void send_serial_number(byte cut_numbers,int increment_serial_number,byte buffered_sending);
#endif
#if defined(FEATURE_SERIAL) && defined(FEATURE_MEMORIES) && defined(FEATURE_COMMAND_LINE_INTERFACE)
void serial_program_memory(PRIMARY_SERIAL_CLS * port_to_use);
#endif
#if defined(FEATURE_SERIAL) && defined(FEATURE_COMMAND_LINE_INTERFACE)
int serial_get_number_input(byte places,int lower_limit, int upper_limit,PRIMARY_SERIAL_CLS * port_to_use,int raise_error_message);
void serial_wpm_set(PRIMARY_SERIAL_CLS * port_to_use);
void serial_qrss_mode();
void process_serial_command(PRIMARY_SERIAL_CLS * port_to_use);
void cli_extended_commands(PRIMARY_SERIAL_CLS * port_to_use);
void cli_keying_compensation(PRIMARY_SERIAL_CLS * port_to_use,String command_arguments);
void cli_autospace_timing_factor(PRIMARY_SERIAL_CLS * port_to_use,String command_arguments);
void cli_paddle_echo_factor(PRIMARY_SERIAL_CLS * port_to_use,String command_arguments);
void cli_timing_command(PRIMARY_SERIAL_CLS * port_to_use,String command_arguments,byte command_called);
void cli_timing_print(PRIMARY_SERIAL_CLS * port_to_use);
void cli_sd_ls_command(PRIMARY_SERIAL_CLS * port_to_use,String directory);
void sd_card_clear_log_file(PRIMARY_SERIAL_CLS * port_to_use,String filename);
void sd_card_print_file(PRIMARY_SERIAL_CLS * port_to_use,String filename);
void sd_card_load_eeprom_from_file(PRIMARY_SERIAL_CLS * port_to_use,String filename);
void sd_card_save_eeprom_to_file(PRIMARY_SERIAL_CLS * port_to_use,String filename);
void cli_eeprom_dump(PRIMARY_SERIAL_CLS * port_to_use);
void serial_set_memory_repeat(PRIMARY_SERIAL_CLS * port_to_use);
void repeat_play_memory(PRIMARY_SERIAL_CLS * port_to_use);
void serial_play_memory(byte memory_number);
int serial_get_number_input(byte places,int lower_limit, int upper_limit,PRIMARY_SERIAL_CLS * port_to_use,int raise_error_message);
void serial_change_wordspace(PRIMARY_SERIAL_CLS * port_to_use);
void serial_switch_tx(PRIMARY_SERIAL_CLS * port_to_use);
void serial_set_dit_to_dah_ratio(PRIMARY_SERIAL_CLS * port_to_use);
void serial_set_serial_number(PRIMARY_SERIAL_CLS * port_to_use);
void serial_set_pot_low_high(PRIMARY_SERIAL_CLS * port_to_use);
void serial_set_sidetone_freq(PRIMARY_SERIAL_CLS * port_to_use);
void serial_wpm_set(PRIMARY_SERIAL_CLS * port_to_use);
#ifdef FEATURE_FARNSWORTH
void serial_set_farnsworth(PRIMARY_SERIAL_CLS * port_to_use);
#endif
void serial_set_weighting(PRIMARY_SERIAL_CLS * port_to_use);
void serial_tune_command (PRIMARY_SERIAL_CLS * port_to_use);
void serial_status(PRIMARY_SERIAL_CLS * port_to_use);
#endif
#ifdef FEATURE_PADDLE_ECHO
void service_paddle_echo();
#endif
#ifdef FEATURE_TRAINING_COMMAND_LINE_INTERFACE
String generate_callsign(byte callsign_mode);
#endif
#if defined(FEATURE_SERIAL) && defined(FEATURE_TRAINING_COMMAND_LINE_INTERFACE) && defined(FEATURE_COMMAND_LINE_INTERFACE)
void serial_cw_practice(PRIMARY_SERIAL_CLS * port_to_use);
void serial_receive_transmit_echo_menu(PRIMARY_SERIAL_CLS * port_to_use);
void receive_transmit_echo_practice(PRIMARY_SERIAL_CLS * port_to_use, byte practice_mode_called);
void serial_receive_practice_menu(PRIMARY_SERIAL_CLS * port_to_use,byte practice_mode);
void serial_set_wordspace_parameters(PRIMARY_SERIAL_CLS * port_to_use,byte mode_select);
void serial_random_menu(PRIMARY_SERIAL_CLS * port_to_use);
void random_practice(PRIMARY_SERIAL_CLS * port_to_use,byte random_mode,byte group_size);
void serial_wordsworth_menu(PRIMARY_SERIAL_CLS * port_to_use);
void wordsworth_practice(PRIMARY_SERIAL_CLS * port_to_use,byte practice_type);
void serial_practice_interactive(PRIMARY_SERIAL_CLS * port_to_use,byte practice_type_called);
void serial_practice_non_interactive(PRIMARY_SERIAL_CLS * port_to_use,byte practice_type_called);
#endif
#if defined(OPTION_PROSIGN_SUPPORT)
char * convert_prosign(byte prosign_code);
#endif
#ifdef DEBUG_MEMORYCHECK
void memorycheck();
#endif
#ifdef FEATURE_CW_DECODER
void service_cw_decoder();
#endif
#if defined(FEATURE_PS2_KEYBOARD) && defined(OPTION_PS2_KEYBOARD_RESET)
void ps2int_write();
#endif
#if defined(OPTION_BLINK_HI_ON_PTT) || (defined(OPTION_WINKEY_BLINK_PTT_ON_HOST_OPEN) && defined(FEATURE_WINKEY_EMULATION))
void blink_ptt_dits_and_dahs(char const * cw_to_send)
#endif
#ifdef FEATURE_USB_KEYBOARD
void KbdRptParser::OnKeyDown(uint8_t mod, uint8_t key);
void KbdRptParser::OnKeyUp(uint8_t mod, uint8_t key);
#endif
#ifdef FEATURE_USB_MOUSE
void MouseRptParser::OnMouseMove(MOUSEINFO *mi);
#endif
#ifdef FEATURE_CAPACITIVE_PADDLE_PINS
uint8_t read_capacitive_pin(int pinToMeasure);
#endif
#ifdef FEATURE_LED_RING
void update_led_ring();
#endif
#ifdef FEATURE_ALPHABET_SEND_PRACTICE
void command_alphabet_send_practice();
#endif
#ifdef FEATURE_PTT_INTERLOCK
void service_ptt_interlock();
#endif
#if defined(OPTION_WINKEY_SEND_BREAKIN_STATUS_BYTE) && defined(FEATURE_WINKEY_EMULATION)
void service_winkey_breakin();
#endif
#if defined(FEATURE_ETHERNET)
void check_for_network_restart();
#endif
#if defined(FEATURE_WEB_SERVER)
void service_web_server();
void web_print_200OK(EthernetClient client);
void web_print_header(EthernetClient client);
void web_print_style_sheet(EthernetClient client);
void web_print_home_link(EthernetClient client);
void web_print_footer(EthernetClient client);
void web_print_title(EthernetClient client);
void web_print_page_network_settings(EthernetClient client);
#if defined(FEATURE_INTERNET_LINK)
void web_print_page_link_settings(EthernetClient client);
#endif
void web_print_page_404(EthernetClient client);
void web_print_page_about(EthernetClient client);
void parse_get(String str);
void web_print_page_main_menu(EthernetClient client);
void web_print_control_radio(EthernetClient client,const char *name,int value,uint8_t checked,const char *caption);
void web_print_control_checkbox(EthernetClient client,const char *name,uint8_t checked,const char *caption);
void web_print_control_textbox(EthernetClient client,const char *name,const char *textbox_class,int textbox_value,const char *front_caption,const char *back_caption);
void web_print_control_textbox(EthernetClient client,const char *name,const char *textbox_class,float textbox_value,const char *front_caption,const char *back_caption){
void web_print_page_keyer_settings(EthernetClient client);
void web_print_page_keyer_settings_process(EthernetClient client);
#if defined(FEATURE_MEMORIES)
void web_print_page_memories(EthernetClient client);
#endif
void web_print_page_control(EthernetClient client);
void web_client_println(EthernetClient client,const __FlashStringHelper *str);
void web_client_print(EthernetClient client,const __FlashStringHelper *str);
void web_client_print(EthernetClient client,String str);
void web_client_print(EthernetClient client,const char *str);
void web_client_println(EthernetClient client,const char *str);
void web_client_print(EthernetClient client,int i);
void web_client_print(EthernetClient client,float f);
void web_client_print(EthernetClient client,unsigned long i);
void web_client_print(EthernetClient client,unsigned int i);
void web_client_println(EthernetClient client,unsigned long i);
void web_client_println(EthernetClient client,unsigned long i,int something);
void web_client_write(EthernetClient client,uint8_t i);
void web_print_page_link_settings_process(EthernetClient client);
void web_print_page_network_settings_process(EthernetClient client);
void web_print_meta_refresh(EthernetClient client,uint8_t ip0,uint8_t ip1,uint8_t ip2,uint8_t ip3,uint8_t refresh_time);
#endif
#if defined(FEATURE_INTERNET_LINK)
void link_key(uint8_t link_key_state);
void add_to_udp_send_buffer(uint8_t bytes_to_send[8],uint8_t number_of_bytes);
void service_udp_send_buffer();
#endif
#if defined(FEATURE_UDP)
void udp_write(uint8_t byte_to_write);
void service_udp_receive();
uint8_t get_udp_receive_buffer_byte();
uint8_t get_udp_receive_buffer_link_command(uint8_t * command,unsigned int * parameter);
void service_internet_link_udp_receive_buffer();
#endif
#ifdef OPTION_NON_ENGLISH_EXTENSIONS
byte convert_unicode_to_send_char_code(byte first_byte,byte second_byte);
#endif
#if defined(FEATURE_SD_CARD_SUPPORT)
void service_sd_card();
#endif
#if defined(FEATURE_SD_CARD_SUPPORT)
void sd_card_log(String string_to_log,byte byte_to_log);
#endif
#ifdef FEATURE_SO2R_BASE
void so2r_set_tx();
void so2r_set_rx();
void so2r_command();
#endif
#ifdef FEATURE_SO2R_SWITCHES
  void so2r_switches();
#endif
