

<?php
 function taxo_page($form, &$form_state){
 	$results1 = array();
  $list_of_vocobulary = array();
  $results1 = db_query("SELECT machine_name FROM {taxonomy_vocabulary}")->fetchAll();
 	foreach ($results1 as $key => $resu) {
 		$list_of_vocobulary[] =  $resu->machine_name;
  	}

   $option =  $list_of_vocobulary;
   $xxxx = taxonomy_get_vocabularies();
   $yyyy =  array();
   foreach ($xxxx as $xxxxs) {
      $yyyy[$xxxxs->machine_name] = $xxxxs->machine_name;
   }
   $test_one =  $results1;
   $test_ones=  $test_one;
    $results3 = db_query("SELECT tid FROM {taxonomy_term_hierarchy}")->fetchAll();
    foreach ($results3 as $key => $value) {
    watchdog("taxonomy_term_hierarchy", '<pre>' . print_r( $value, true) . '</pre>');
    }
  $one = array();
  $vocos = taxonomy_get_vocabularies();
  foreach ($vocos as $key => $voco) {
  	 $one[] = $voco->vid;
  }
  $selected = isset($form_state['taxo']['voco_types']) ? $form_state['taxo']['voco_types'] : key($one);
  $option_first =  drupal_map_assoc($selected);
$form['taxo']['voco_types'] = array(
  '#title' => t('vocobulary Types'),
  '#type' => 'select',
  '#options' => $yyyy,
  '#default_value' => $selected,
  '#validated' => TRUE,
  '#ajax' => array(
        'callback' => 'dropdown_onclick_function',
        'wrapper'  => 'Content_titles-replace',
        'event'    => 'change',
        'method'   => 'replace',
        'effect'   => 'fade',
        ), 
);

$form['taxo']['terms_types'] = array(
  '#title' => t('Terms Types'),
  '#type' => 'select',
  '#options' => '',
  '#multiple' => TRUE,
  '#validated' => TRUE,
  '#prefix' => '<div id="Content_titles-replace">',
  '#suffix' => '</div>',
  '#options' => '<div id="Content_titles-replace">', 
  '#ajax' => array(
        'callback' => 'dropdown_secons_onclick_function',
        'wrapper'  => 'Node_titles-replace',
        'event'    => 'change',
        'method'   => 'replace',
        'effect'   => 'fade',
        ), 
);

$form['taxo']['list_of_the_nodes'] = array(
  '#title' => t('Node list'),
  '#type' => 'select',
  '#options' => '',
    '#multiple' => TRUE,
  '#prefix' => '<div id="Node_titles-replace">',
  '#suffix' => '</div>',
  '#options' => '<div id="Node_titles-replace">', 
  '#validated' => TRUE,
);

$form['taxo']['submit'] = array(
    '#type'  => 'submit',
    '#value' => t('Submit'),
  );
 	return $form;
 }

 function taxo_page_submit($form, &$form_state){
  $termValue23 = $form_state['values']['terms_types'];
  $inter = node_load($termValue23);
   $kan = taxonomy_select_nodes($termValue);
   foreach ($kan as $key => $nid) {
    $node90 = node_load($nid);
    $title_node[] = $node90->title;
   }

  $form_state['redirect'] = array (
  'admin/mycontent/result'
    );
 }
   
   function dropdown_secons_onclick_function($form,&$form_state){
      $selVals_node= $form_state['values']['terms_types'];
      $node_tit = entity_load('taxonomy_term', FALSE, array('name' => $selVals_node));
      $selVals_node_ids= db_query('SELECT tid FROM {taxonomy_term_data} WHERE name = :name', array(':name' =>$selVals_node))->fetchAll();
      $tree = taxonomy_get_tree($selVals_node);
      $selVals_node_ids_refines = array();
      foreach ($selVals_node_ids as $selVals_node_id) {
        $selVals_node_ids_refines[$selVals_node_id->tid] = $selVals_node_id->tid;
       }
       $node_title_each[] = node_load_multiple(array(),array('nid'=> $selVals_node_ids_refines));
      $arg9090 = arg();
      $query9090 = db_select('node','n');
      $query9090->join('taxonomy_index','ti','n.nid=ti.nid');
      $result_of_new_9090 = $query9090->execute()->fetchObject();
   }
   function dropdown_onclick_function($form, &$form_state){
   	  $selVals= $form_state['values']['voco_types'];
   	  $pppp =  taxonomy_vocabulary_machine_name_load('selVals');
       $nid = '15';
       $node = node_load($nid);
       $title = $node;
       $vocabulary_id= db_query('SELECT vid FROM {taxonomy_vocabulary} WHERE name = :name', array(':name' =>$selVals))->fetchObject();
       $term_id_finals_fetch = db_query("SELECT name FROM {taxonomy_term_data} WHERE vid = :vid", array(':vid' =>$vocabulary_id->vid))->fetchAll();
       $terms_name = array();
        foreach ($term_id_finals_fetch as $term_id_final) {
          $terms_name[$term_id_final->name] = $term_id_final->name;
        }
      $terms_sels = entity_load('taxonomy_term', FALSE, array('vid' => $selVals));
   	  foreach ($terms_sels as $key => $terms_sel) {
      $final_taxo[] =   $terms_sel->name;
   	  }
        $form['taxo']['terms_types']['#options'] = $terms_name;
        return $form['taxo']['terms_types'];
}
 function my_content_page(){
  # implement idea 2.3

 }
